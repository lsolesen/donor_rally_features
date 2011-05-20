<?php
/**
 * @file
 * dr_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dr_base_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dr_base_dashboard';
  $context->description = 'Layout editor';
  $context->tag = 'donor rally';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
        'dashboard/*' => 'dashboard/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dr_base-welcome' => array(
          'module' => 'dr_base',
          'delta' => 'welcome',
          'region' => 'content',
          'weight' => -42,
        ),
        'spaces_dashboard-editor' => array(
          'module' => 'spaces_dashboard',
          'delta' => 'editor',
          'region' => 'content',
          'weight' => -10,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout editor');
  t('donor rally');
  $export['dr_base_dashboard'] = $context;

  return $export;
}
