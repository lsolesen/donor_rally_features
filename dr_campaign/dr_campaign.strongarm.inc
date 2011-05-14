<?php
/**
 * @file
 * dr_campaign.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dr_campaign_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_campaign';
  $strongarm->value = 'edit-group';
  $export['additional_settings__active_tab_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_campaign';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '3',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'menu' => '-1',
    'path' => '8',
    'og_description' => '-2',
    'og_selective' => '2',
    'og_register' => '4',
    'og_directory' => '1',
    'og_private' => '0',
  );
  $export['content_extra_weights_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_campaign';
  $strongarm->value = array();
  $export['menu_options_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_campaign';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_campaign';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_campaign';
  $strongarm->value = '0';
  $export['node_preview_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_campaign';
  $strongarm->value = 0;
  $export['node_submitted_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_campaign';
  $strongarm->value = 'group';
  $export['og_content_type_usage_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_content_type_campaign';
  $strongarm->value = 'omitted';
  $export['og_group_content_type_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_campaign';
  $strongarm->value = '';
  $export['og_max_groups_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_campaign';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_campaign'] = $strongarm;

  return $export;
}
