<?php
/**
 * @file
 * dr_campaign.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function dr_campaign_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  list($module, $api) = func_get_args();
  if ($module == "spaces" && $api == "spaces") {
    return array("version" => 3);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function dr_campaign_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function dr_campaign_node_info() {
  $items = array(
    'campaign' => array(
      'name' => t('Campaign'),
      'description' => t('TODO good description of what a campaign is'),
      'base' => 'node_content',
      'has_title' => '1',
      'title_label' => t('Campaign name'),
      'help' => '',
    ),
  );
  return $items;
}
