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
    'body_field' => '2',
    'revision_information' => '5',
    'author' => '4',
    'options' => '6',
    'menu' => '-2',
    'path' => '7',
    'og_description' => '-3',
    'og_selective' => '1',
    'og_register' => '3',
    'og_directory' => '0',
    'og_private' => '-1',
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
