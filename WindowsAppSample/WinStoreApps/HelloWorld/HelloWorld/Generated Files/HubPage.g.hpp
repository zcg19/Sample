﻿

//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"
#include "HubPage.xaml.h"




void ::HelloWorld::HubPage::InitializeComponent()
{
    if (_contentLoaded)
        return;

    _contentLoaded = true;

    // Call LoadComponent on ms-appx:///HubPage.xaml
    ::Windows::UI::Xaml::Application::LoadComponent(this, ref new ::Windows::Foundation::Uri(L"ms-appx:///HubPage.xaml"), ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);

    // Get the Button named 'backButton'
    backButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"backButton"));
    // Get the TextBlock named 'pageTitle'
    pageTitle = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"pageTitle"));
}

void ::HelloWorld::HubPage::Connect(int connectionId, Platform::Object^ target)
{
    switch (connectionId)
    {
    case 1:
        (safe_cast<::Windows::UI::Xaml::Controls::Hub^>(target))->SectionHeaderClick +=
            ref new ::Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler(this, (void (::HelloWorld::HubPage::*)(Platform::Object^, Windows::UI::Xaml::Controls::HubSectionHeaderClickEventArgs^))&HubPage::Hub_SectionHeaderClick);
        break;
    case 2:
        (safe_cast<::Windows::UI::Xaml::Controls::ListViewBase^>(target))->ItemClick +=
            ref new ::Windows::UI::Xaml::Controls::ItemClickEventHandler(this, (void (::HelloWorld::HubPage::*)(Platform::Object^, Windows::UI::Xaml::Controls::ItemClickEventArgs^))&HubPage::ItemView_ItemClick);
        break;
    }
    (void)connectionId; // Unused parameter
    (void)target; // Unused parameter
    _contentLoaded = true;
}

