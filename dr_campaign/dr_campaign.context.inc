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
  $context->description = 'Layout editor';
  $context->tag = 'donor rally campaign';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'rally' => 'rally',
        'rally/*' => 'rally/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dr_campaign-layout_editor' => array(
          'module' => 'dr_campaign',
          'delta' => 'layout_editor',
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout editor');
  t('donor rally campaign');

  $export['dr_campaign'] = $context;
  return $export;
}
