/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.GeneralTransform
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.UI.Xaml.Media.GeneralTransform.hpp"

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

		GeneralTransform::GeneralTransform(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
			TITANIUM_LOG_DEBUG("GeneralTransform::ctor");
		}

		void GeneralTransform::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("GeneralTransform::postCallAsConstructor ", this);

		}

		::Windows::UI::Xaml::Media::GeneralTransform^ GeneralTransform::unwrapWindows_UI_Xaml_Media_GeneralTransform() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::GeneralTransform^>(wrapped__);
		}

		::Windows::UI::Xaml::Media::GeneralTransform^ GeneralTransform::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_GeneralTransform();
		}

		void GeneralTransform::wrap(::Windows::UI::Xaml::Media::GeneralTransform^ object)
		{
			wrapped__ = object;
		}

		void GeneralTransform::JSExportInitialize()
		{
			JSExport<GeneralTransform>::SetClassVersion(1);
			JSExport<GeneralTransform>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(GeneralTransform, Inverse);
			TITANIUM_ADD_PROPERTY_READONLY(GeneralTransform, InverseCore);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TransformPoint);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TryTransform);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TransformBounds);
		}

		TITANIUM_PROPERTY_GETTER(GeneralTransform, Inverse)
		{
			auto value = unwrap()->Inverse;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::GeneralTransform>();
			result_wrapper->wrap(value);

		}

		TITANIUM_PROPERTY_GETTER(GeneralTransform, InverseCore)
		{
			auto value = unwrap()->InverseCore;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::GeneralTransform>();
			result_wrapper->wrap(value);

		}

		TITANIUM_FUNCTION(GeneralTransform, TransformPoint)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_point = static_cast<JSObject>(_0);
			::Windows::Foundation::Point point;
			// Assign fields explicitly since we didn't use a constructor

			auto object_point_X_ = static_cast<float>(static_cast<double>(object_point_X));


			auto object_point_Y_ = static_cast<float>(static_cast<double>(object_point_Y));


				auto method_result = unwrap()->TransformPoint(point);
			auto result = context.CreateObject();




			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched GeneralTransform::TransformPoint with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(GeneralTransform, TryTransform)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0);
			auto object_inPoint = static_cast<JSObject>(_0);
			::Windows::Foundation::Point inPoint;
			// Assign fields explicitly since we didn't use a constructor

			auto object_inPoint_X_ = static_cast<float>(static_cast<double>(object_inPoint_X));


			auto object_inPoint_Y_ = static_cast<float>(static_cast<double>(object_inPoint_Y));


				auto _1 = arguments.at(1);
			auto object_outPoint = static_cast<JSObject>(_1);
			::Windows::Foundation::Point outPoint;
			// Assign fields explicitly since we didn't use a constructor

			auto object_outPoint_X_ = static_cast<float>(static_cast<double>(object_outPoint_X));


			auto object_outPoint_Y_ = static_cast<float>(static_cast<double>(object_outPoint_Y));


				auto method_result = unwrap()->TryTransform(inPoint, &outPoint);

			auto out_1 = context.CreateObject();




				_1 = out_1;
				return result;
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched GeneralTransform::TryTransform with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(GeneralTransform, TransformBounds)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_rect = static_cast<JSObject>(_0);
			::Windows::Foundation::Rect rect;
			// Assign fields explicitly since we didn't use a constructor

			auto object_rect_X_ = static_cast<float>(static_cast<double>(object_rect_X));


			auto object_rect_Y_ = static_cast<float>(static_cast<double>(object_rect_Y));


			auto object_rect_Width_ = static_cast<float>(static_cast<double>(object_rect_Width));


			auto object_rect_Height_ = static_cast<float>(static_cast<double>(object_rect_Height));


				auto method_result = unwrap()->TransformBounds(rect);
			auto result = context.CreateObject();








			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched GeneralTransform::TransformBounds with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium