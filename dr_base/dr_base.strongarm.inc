<?php

/**
 * Implementation of hook_strongarm().
 */
function dr_base_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_features';
  $strongarm->value = array(
    'dr_campaign' => '1',
    'spaces_dashboard' => '1',
  );

  $export['spaces_features'] = $strongarm;
  return $export;
}
