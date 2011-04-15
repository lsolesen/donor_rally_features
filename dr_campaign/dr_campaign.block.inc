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
  return array(
    'subject' => '',
    'content' => 'TODO',
  );
}