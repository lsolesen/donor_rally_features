<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function dr_campaign_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spaces_dashboard-custom-1';
  $context->description = 'Dashboard';
  $context->tag = 'Dashboard';
  $context->conditions = FALSE;
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-dr_campaign-block_1' => array(
          'module' => 'views',
          'delta' => 'dr_campaign-block_1',
          'region' => 'content_top',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');

  $export['spaces_dashboard-custom-1'] = $context;
  return $export;
}