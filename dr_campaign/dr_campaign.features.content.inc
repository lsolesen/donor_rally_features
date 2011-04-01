<?php

/**
 * Implementation of hook_content_default_fields().
 */
function dr_campaign_content_default_fields() {
  $fields = array();

  // Exported field: field_campaign_goal
  $fields['campaign-field_campaign_goal'] = array(
    'field_name' => 'field_campaign_goal',
    'type_name' => 'campaign',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '$',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_campaign_goal][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Campaign goal',
      'weight' => '-4',
      'description' => 'Enter the goal for this campaign.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Campaign goal');

  return $fields;
}
