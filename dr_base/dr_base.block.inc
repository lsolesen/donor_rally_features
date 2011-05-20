<?php
/**
 * Donor Rally Welcome block.
 */
function _dr_base_block_welcome() {
  if (user_access('administer site configuration')) {
    $block = array();
    $block['subject'] = t('Welcome to Donor Rally');

    // Build menu links.
    $links = array();

    // Donor Rally Campaigns
    $item = menu_get_item('node/add/campaign');
    if ($item['access']) {
      $links[] = array(
        'title' => t('Add a new @type', array('@type' => node_type_get_name('campaign'))),
        'href' => 'node/add/campaign',
      );
    }

    // Features.
    $item = menu_get_item('features');
    if ($item['access']) {
      $links[] = array(
        'title' => t('Customize Features'),
        'href' => 'features',
      );
    }

    // TODO we need a video in here.
    $video = '<iframe src="http://player.vimeo.com/video/21899054?title=0&amp;byline=0&amp;portrait=0" width="400" height="225" frameborder="0"></iframe>';

    // Customize dashboard.
    if (spaces_access_admin()) {
      $link = l(t('customizing the dashboard'), $_GET['q'], array('fragment' => 'block-spaces_dashboard-editor', 'attributes' => array('class' => array('block-toggle'))));
      $admin = t('You can remove this block by !customize.', array('!customize' => $link));
    }

    $block['content'] = theme('dr_base_welcome', array('video' => $video, 'links' => $links, 'admin' => $admin));
    return $block;
  }
}