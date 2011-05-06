<?php

/**
 * Implementation of hook_strongarm().
 */
function dr_campaign_strongarm() {
  $export = array();
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
  $strongarm->name = 'node_options_campaign';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );

  $export['node_options_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_campaign';
  $strongarm->value = 'group';

  $export['og_content_type_usage_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_campaign';
  $strongarm->value = '';

  $export['og_max_groups_campaign'] = $strongarm;
  return $export;
}
