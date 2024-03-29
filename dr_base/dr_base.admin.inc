<?php

// $Id$

/**
 * @file
 * Donor Rally administrator settings form.
 */

/**
 * Global competitive drive settings
 */
function dr_base_settings_form($form, $form_state) {
  $form = array();

  $options = module_invoke_all('dr_base_payment_gateway');
  if (empty($options)) {
    drupal_set_message(t('No payment gateways found. Payment gateways can be enabled on the <a href="!url">modules page</a>.', array('!url' => url('admin/modules'))), 'error');
  }
  else {
    $form['payment_gateway'] = array(
      '#title' => t('Donor Rally Payment Gateway'),
      '#type' => 'select',
      '#required' => TRUE,
      '#options' => $options,
      '#description' => t('Select payment gateway to use. Gateways can be enabled on the <a href="!url">modules page</a>.', array('!url' => url('admin/modules'))),
      '#default_value' => variable_get('dr_base_payment_gateway', ''),
    );
  }

  $form['dr_base_goal'] = array(
    '#type' => 'textfield',
    '#title' => t('Total Fundraising Goal'),
    '#description' => t('This will be used for the total on the site-wide thermometer.'),
    '#required' => TRUE,
    '#default_value' => variable_get('dr_base_goal', 314159265),
  );

  $form['point_scales'] = array(
    '#type' => 'fieldset',
    '#title' => t('Point conversions'),
  );
  $form['point_scales']['cash'] = array(
    '#title' => t('Cash scale'),
    '#description' => t('Scaling factor to turn dollars into points'),
    '#type' => 'textfield',
    '#default_value' => variable_get('dr_base_cash_scale', 1.0),
    '#required' => TRUE,
  );

  if (variable_get('dr_base_debug', FALSE)) {
    $form['alias_teams'] = array(
      '#title' => t('Alias competititon teams to existing Tracking_Code values?'),
      '#type' => 'textfield',
      '#description' => t('Put yes here to alias teams to DIA cash totals data'),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // @TODO this should just use system_settings_form().
  return $form;
}

/**
 * Validates our global settings form.
 */
function dr_base_settings_form_validate($form, &$form_state) {
  // TODO abstract this out to dr_base_inkind module.
  foreach (array('cash', 'food', 'volunteer') as $element) {
    if ((float) $form_state['values'][$element] < 0.0) {
      form_set_error($element, t('%element must be greater than or equal to zero.', array('%element' => $form['point_scales'][$element]['#title'])));
    }
  }
  if ($form_state['values']['payment_gateway'] && !module_exists($form_state['values']['payment_gateway'])) {
    form_set_error('payment_gateway', t('Payment gateway %module not found.', array('%module' => $form_state['values']['payment_gateway'])));
  }
}

/**
 * Saves our global settings form.
 */
function dr_base_settings_form_submit($form, &$form_state) {
  // TODO abstract this out to dr_base_inkind module.
  variable_set('dr_base_cash_scale', $form_state['values']['cash']);
  variable_set('dr_base_food_scale', $form_state['values']['food']);
  variable_set('dr_base_volunteer_scale', $form_state['values']['volunteer']);
  variable_set('dr_base_goal', $form_state['values']['dr_base_goal']);
  if (isset($form_state['values']['payment_gateway'])) {
    variable_set('dr_base_payment_gateway', $form_state['values']['payment_gateway']);
  }

  if (variable_get('dr_base_debug', FALSE)) {
    if ($form_state['values']['alias_teams'] === 'yes') {
      _dr_base_set_debug_aliases();
    }
  }
  dr_base_refresh_all();
}

