/**
 * Windows Native Wrapper for Windows.UI.Xaml.SetterBase
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.SetterBase.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		SetterBase::SetterBase(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void SetterBase::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::SetterBase^ SetterBase::unwrapWindows_UI_Xaml_SetterBase() const
		{
			return dynamic_cast<::Windows::UI::Xaml::SetterBase^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::SetterBase^ SetterBase::unwrap() const
		{
			return unwrapWindows_UI_Xaml_SetterBase();
		}

		void SetterBase::wrap(::Windows::UI::Xaml::SetterBase^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void SetterBase::JSExportInitialize()
		{
			JSExport<SetterBase>::SetClassVersion(1);
			JSExport<SetterBase>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(SetterBase, IsSealed);
		}

		TITANIUM_PROPERTY_GETTER(SetterBase, IsSealed)
		{
			auto value = unwrap()->IsSealed;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
