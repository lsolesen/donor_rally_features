<?php
/**
 * @file
 * Blocks for the Donor Rally Campaign feature.
 */

/**
 * Campaign thermometer block.
 */
function _dr_campaign_block_campaign_thermometer() {
  $space = spaces_get_space();
  if (!($space->type == 'og' && $space->group->type == 'campaign')) {
    // Must be a campaign node.
    return;
  }
  $node = $space->group;

  $goal = dr_campaign_get_goal($node);
  $vars['total_raw_goal'] = $goal;
  $vars['total_raw_goal_view'] = _dr_base_format_value($goal);

  $total = dr_campaign_get_total($node);
  $vars['total_raw'] = $total;
  $vars['total_raw_view'] = _dr_base_format_value($total);

  $vars['edit_link'] = node_access('update', $node) ? l(t('Change campaign goal'), 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination())) : '';

  return array(
    'subject' => '',
    'content' => theme('dr_base_thermometer', $vars),
  );
}

/**
 * Layout editor block.
 */
function _dr_campaign_block_layout_editor() {
  // Ensure that the dashboard editor does not appear on the same page as
  // the context editor. The two will collide.
  $context = context_get('spaces', 'rally') ? context_get('context', context_get('spaces', 'rally')) : FALSE;
  if (user_access('administer campaign layout') && $context) {
    return array(
      'subject' => '',
      'content' => drupal_get_form('dr_campaign_layout_editor', array($context)),
    );
  }
}

/**
 * Form builder: campaign landing layout editor. Clones and overrides
 * form built by context_ui_editor().
 *
 * Modeled after the spaces_dashboard_editor form.
 */
function dr_campaign_layout_editor(&$form_state, $contexts) {
  $form = array();
  if ($context = context_get('spaces', 'rally')) {
    context_set('spaces_layout', 'form_build', TRUE);

    // Clone the context_ui_editor form and make some changes.
    $form = context_ui_editor($form_state, $contexts);
    unset($form['contexts'][$context]['#type']);
    // Hide conditions.
    $form['contexts'][$context]['condition']['#access'] = FALSE;
    // Hide reactions other than blocks.
    foreach (array_keys(context_reactions()) as $reaction) {
      if ($reaction !== 'block' && isset($form['contexts'][$context]["reaction-{$reaction}"])) {
        $form['contexts'][$context]["reaction-{$reaction}"]['#access'] = FALSE;
      }
    }
    // Alter allowed layouts
    if (module_exists('context_layouts')) {
      // TODO
      $layouts = variable_get('spaces_dashboard_layouts', array());
      if (!empty($layouts) && isset($form['contexts'][$context]['reaction-block']['layout'])) {
        $layouts = array_filter($layouts);
        $layouts[0] = 1;
        $form['contexts'][$context]['reaction-block']['layout']['layout']['#options'] = array_intersect_key($form['contexts'][$context]['reaction-block']['layout']['layout']['#options'], $layouts);
      }
    }
    // We need to call this alter manually against our form.
    if (module_exists('spaces') && $space = spaces_get_space()) {
      spaces_form_context_ui_editor_alter($form, $form_state);
    }
  }
  return $form;
}
