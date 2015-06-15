/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.SolidColorBrush
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Media.Brush.hpp"
#include "Windows.UI.Xaml.Media.SolidColorBrush.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Media
				{

		SolidColorBrush::SolidColorBrush(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Media::Brush(js_context)
		{
			TITANIUM_LOG_DEBUG("SolidColorBrush::ctor");
		}

		void SolidColorBrush::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("SolidColorBrush::postCallAsConstructor ", this);
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_color = static_cast<JSObject>(_0);
			::Windows::UI::Color color;
			// Assign fields explicitly since we didn't use a constructor

			auto object_color_A_ = static_cast<uint32_t>(object_color_A);


			auto object_color_R_ = static_cast<uint32_t>(object_color_R);


			auto object_color_G_ = static_cast<uint32_t>(object_color_G);


			auto object_color_B_ = static_cast<uint32_t>(object_color_B);


				wrapped__ = ref new ::Windows::UI::Xaml::Media::SolidColorBrush(color);
			}
			if (arguments.size() == 0) {

				wrapped__ = ref new ::Windows::UI::Xaml::Media::SolidColorBrush();
			}

		}

		::Windows::UI::Xaml::Media::SolidColorBrush^ SolidColorBrush::unwrapWindows_UI_Xaml_Media_SolidColorBrush() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::SolidColorBrush^>(wrapped__);
		}

		::Windows::UI::Xaml::Media::SolidColorBrush^ SolidColorBrush::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_SolidColorBrush();
		}

		void SolidColorBrush::wrap(::Windows::UI::Xaml::Media::SolidColorBrush^ object)
		{
			wrapped__ = object;
		}

		void SolidColorBrush::JSExportInitialize()
		{
			JSExport<SolidColorBrush>::SetClassVersion(1);
			JSExport<SolidColorBrush>::SetParent(JSExport<Windows::UI::Xaml::Media::Brush>::Class());

			TITANIUM_ADD_PROPERTY(SolidColorBrush, Color);
			TITANIUM_ADD_PROPERTY_READONLY(SolidColorBrush, ColorProperty);
		}

		TITANIUM_PROPERTY_SETTER(SolidColorBrush, Color)
		{
			auto object_value = static_cast<JSObject>(argument);
			::Windows::UI::Color value;
			// Assign fields explicitly since we didn't use a constructor

			auto object_value_A_ = static_cast<uint32_t>(object_value_A);


			auto object_value_R_ = static_cast<uint32_t>(object_value_R);


			auto object_value_G_ = static_cast<uint32_t>(object_value_G);


			auto object_value_B_ = static_cast<uint32_t>(object_value_B);


			unwrap()->Color = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(SolidColorBrush, Color)
		{
			auto value = unwrap()->Color;
			auto context = get_context();

			auto result = context.CreateObject();








		}

		TITANIUM_PROPERTY_GETTER(SolidColorBrush, ColorProperty)
		{
			auto value = unwrap()->ColorProperty;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium