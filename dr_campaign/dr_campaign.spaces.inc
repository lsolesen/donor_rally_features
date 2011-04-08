<?php

/**
 * Implementation of hook_spaces_presets().
 */
function dr_campaign_spaces_presets() {
  $export = array();
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'dr_campaign';
  $spaces_presets->title = 'Campaign';
  $spaces_presets->description = 'TODO: a good description of what campaigns are';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'site_frontpage' => 'rally',
      'spaces_og_selective' => '3',
      'spaces_og_register' => 0,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
    ),
    'context' => array(
      'dr_campaign-landing_page:reaction:block' => array(
        'blocks' => array(
          'dr_campaign-campaign_thermometer' => array(
            'module' => 'dr_campaign',
            'delta' => 'campaign_thermometer',
            'region' => 'sidebar_second',
            'weight' => 0,
          ),
          'views-dr_campaign_data-block_1' => array(
            'module' => 'views',
            'delta' => 'dr_campaign_data-block_1',
            'region' => 'highlight',
            'weight' => 0,
          ),
        ),
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Campaign');
  t('TODO: a good description of what campaigns are');

  $export['dr_campaign'] = $spaces_presets;
  return $export;
}
