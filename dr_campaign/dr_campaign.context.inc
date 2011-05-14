<?php
/**
 * @file
 * dr_campaign.context.inc
 */

/**
 * Implements hook_context_default_contexts().
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
        'views-dr_campaign-active_campaigns' => array(
          'module' => 'views',
          'delta' => 'dr_campaign-active_campaigns',
          'region' => 'content',
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
