/**
 * Windows Native Wrapper for Windows.UI.Xaml.Data.BindingExpressionBase
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Data.BindingExpressionBase.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Data
				{

		BindingExpressionBase::BindingExpressionBase(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void BindingExpressionBase::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Data::BindingExpressionBase^ BindingExpressionBase::unwrapWindows_UI_Xaml_Data_BindingExpressionBase() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Data::BindingExpressionBase^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Data::BindingExpressionBase^ BindingExpressionBase::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Data_BindingExpressionBase();
		}

		void BindingExpressionBase::wrap(::Windows::UI::Xaml::Data::BindingExpressionBase^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void BindingExpressionBase::JSExportInitialize()
		{
			JSExport<BindingExpressionBase>::SetClassVersion(1);
			JSExport<BindingExpressionBase>::SetParent(JSExport<Titanium::Module>::Class());

		}

				} // namespace Data
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
