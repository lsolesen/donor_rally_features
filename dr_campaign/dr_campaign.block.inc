<?php
/**
 * @file
 * Blocks for the Donor Rally Campaign feature.
 */

/**
 * Campaign thermometer block.
 */
function _dr_campaign_block_campaign_thermometer() {
  if (!($node = menu_get_object()) && $node->type != 'campaign') {
    // Must be a campaign node.
    return;
  }
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