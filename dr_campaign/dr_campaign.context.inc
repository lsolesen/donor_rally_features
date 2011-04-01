<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function dr_campaign_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dr_campaign';
  $context->description = 'Context for individual Donor Rally campaigns';
  $context->tag = 'donor rally campaign';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campaign' => 'campaign',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dr_campaign-campaign_thermometer' => array(
          'module' => 'dr_campaign',
          'delta' => 'campaign_thermometer',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for individual Donor Rally campaigns');
  t('donor rally campaign');

  $export['dr_campaign'] = $context;
  return $export;
}
