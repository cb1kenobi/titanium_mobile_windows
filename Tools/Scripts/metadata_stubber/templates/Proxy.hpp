<%
String.prototype.to_windows_name = function() {
	return this.replace(/\./g, '::');
};

var full_name = name;
var namespaces = ['Titanium'];
namespaces = namespaces.concat(full_name.split('.'));
var base_name = namespaces[namespaces.length - 1];
var underscore_name = full_name.replace(/\./g, '_');
var name_upper = underscore_name.toUpperCase();
var windows_name = full_name.to_windows_name();
var unique_methods = [];
var parent_name = "Module";
if (parent && parent.indexOf('[mscorlib]') != 0) {
	parent_name = parent.trim();
}
-%>
/**
 * Windows Native Wrapper for <%= full_name %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _<%= name_upper %>_HPP_
#define _<%= name_upper %>_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "TitaniumWindows/Utility.hpp"
<%
if (parent_name == 'Module') { -%>
#include "Titanium/Module.hpp"
<%
} else { -%>
#include "<%= parent_name %>.hpp"
<%
} -%>

<% for (var i = 0; i < namespaces.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= namespaces[i] %>
<%= Array(i + 1).join('\t') %>{
<% } %>

		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT <%= base_name %> : public Titanium::<%= parent_name.to_windows_name() %>, public JSExport<<%= base_name %>>
		{

		public:
<%
for (property_name in properties) {
	if (properties[property_name]['setter']) { -%>
			TITANIUM_PROPERTY_DEF(<%= property_name %>);
<%
	} else {
-%>
			TITANIUM_PROPERTY_READONLY_DEF(<%= property_name %>);
<%
	}
}
-%>

<%
if (methods) {
	for (var i = 0; i < methods.length; i++) {
		var method = methods[i];
		// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
		if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
			method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0 || method.name == '.ctor') {
				continue;
		}
		// Skip non-public methods
		if (method.attributes.indexOf("public") == -1) {
			continue;
		}
		// Guard against overloaded methods, we'll have to handle each variation in one JS bridge method in cpp
		if (unique_methods.indexOf(method.name) != -1) {
			continue;
		}
		unique_methods.unshift(method.name);
-%>
			TITANIUM_FUNCTION_DEF(<%= method.name %>);
<%
	}
}
-%>

			<%= base_name %>(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~<%= base_name %>() = default;
			<%= base_name %>(const <%= base_name %>&) = default;
			<%= base_name %>& operator=(const <%= base_name %>&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			<%= base_name %>(<%= base_name %>&&)                 = default;
			<%= base_name %>& operator=(<%= base_name %>&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			::<%= windows_name %>^ unwrap<%= underscore_name %>() const;
			void wrap(::<%= windows_name %>^ object);
<%
if (parent_name == 'Module') { -%>

		protected:
			::<%= windows_name %>^ wrapped__;
<%
} -%>

		private:
			::<%= windows_name %>^ unwrap() const;

		};

<% for (var i = namespaces.length - 2; i>= 0; i--) { -%>
<%= Array(i + 1).join('\t') %>} // namespace <%= namespaces[i] %>
<% } -%>
#endif // _<%= name_upper %>_HPP_
