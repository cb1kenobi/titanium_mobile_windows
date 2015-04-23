/**
 * Windows Native Wrapper for Windows.UI.Xaml.FrameworkTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.FrameworkTemplate.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		FrameworkTemplate::FrameworkTemplate(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void FrameworkTemplate::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::FrameworkTemplate^ FrameworkTemplate::unwrapWindows_UI_Xaml_FrameworkTemplate() const
		{
			return dynamic_cast<::Windows::UI::Xaml::FrameworkTemplate^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::FrameworkTemplate^ FrameworkTemplate::unwrap() const
		{
			return unwrapWindows_UI_Xaml_FrameworkTemplate();
		}

		void FrameworkTemplate::wrap(::Windows::UI::Xaml::FrameworkTemplate^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void FrameworkTemplate::JSExportInitialize()
		{
			JSExport<FrameworkTemplate>::SetClassVersion(1);
			JSExport<FrameworkTemplate>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
