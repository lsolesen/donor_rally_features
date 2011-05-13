<?php
/**
 * @file
 * dr_campaign.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function dr_campaign_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dr_campaign';
  $view->description = 'List of campaigns';
  $view->tag = 'donor rally campaign';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 27;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty test';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No active campaigns';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['fields']['title']['spaces'] = array(
    'type' => 'spaces_og',
    'frontpage' => 1,
  );
  /* Field: Content: Campaign goal */
  $handler->display->display_options['fields']['field_campaign_goal']['id'] = 'field_campaign_goal';
  $handler->display->display_options['fields']['field_campaign_goal']['table'] = 'field_data_field_campaign_goal';
  $handler->display->display_options['fields']['field_campaign_goal']['field'] = 'field_campaign_goal';
  $handler->display->display_options['fields']['field_campaign_goal']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_goal']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_goal']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_campaign_goal']['field_api_classes'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Active campaigns */
  $handler = $view->new_display('block', 'Active campaigns', 'active_campaigns');
  $translatables['dr_campaign'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Empty test'),
    t('No active campaigns'),
    t('Active campaigns'),
  );
  $export['dr_campaign'] = $view;

  $view = new view;
  $view->name = 'dr_campaign_data';
  $view->description = 'Campaign data view';
  $view->tag = 'donor rally campaign';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'spaces_feature';
  $handler->display->display_options['access']['spaces_feature'] = 'dr_campaign';
  $handler->display->display_options['access']['perm'] = '';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 1;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $handler->display->display_options['fields']['title']['spaces'] = array(
    'type' => 'spaces_og',
    'frontpage' => 0,
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '$space = spaces_get_space();
if ($space->type = \'og\') {
  return $space->group->nid;
}';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign' => 'campaign',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: Campaign description */
  $handler = $view->new_display('block', 'Campaign description', 'campaign_description');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_campaign_description']['id'] = 'field_campaign_description';
  $handler->display->display_options['fields']['field_campaign_description']['table'] = 'field_data_field_campaign_description';
  $handler->display->display_options['fields']['field_campaign_description']['field'] = 'field_campaign_description';
  $handler->display->display_options['fields']['field_campaign_description']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_description']['field_api_classes'] = 0;

  /* Display: Logo/image */
  $handler = $view->new_display('block', 'Logo/image', 'campaign_logo');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_campaign_logo']['id'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['table'] = 'field_data_field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['field'] = 'field_campaign_logo';
  $handler->display->display_options['fields']['field_campaign_logo']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_campaign_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaign_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_campaign_logo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_campaign_logo']['field_api_classes'] = 0;
  $translatables['dr_campaign_data'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Campaign description'),
    t('Logo/image'),
  );
  $export['dr_campaign_data'] = $view;

  return $export;
}
