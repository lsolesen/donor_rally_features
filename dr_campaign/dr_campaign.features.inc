<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function dr_campaign_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "spaces" && $api == "spaces") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function dr_campaign_node_info() {
  $items = array(
    'campaign' => array(
      'name' => t('Campaign'),
      'module' => 'features',
      'description' => t('TODO good description of what a campaign is'),
      'has_title' => '1',
      'title_label' => t('Campaign name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
