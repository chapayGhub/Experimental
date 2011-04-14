package menu;

import groovy.text.Template
import groovy.text.SimpleTemplateEngine

class MenuGenerator {

	// String passThru = "/oe/passThroughSecurity.ls?sendToApp=${app}&postUrl=${uri}"

	String generateMenu(menu) {

		if (menu.@enabled == true) {
	
			String s = "<ul id='sample-menu-1' class='sf-menu'>"
			menu.children().each {

				if (it.@enabled == true) {
					String status = ""
					/*if (it.@status!=""){status = "onmouseover=\"window.status='${it.@status}'\" "	}*/

					String passThru = "/oe/passThroughSecurity.ls?sendToApp=${app}&postUrl=${uri}"

					s = "${s}<li><a ${status} href='${it.@uri}'>${it.@label}</a>"
					Integer num = it.children().size()
					if (num > 0) {
						s = "${s}<ul>"
						it.children().each {
							s = s + processEachChild(it)
						}
						s = "${s}</ul>"
					}
					s = "${s}</li>"
				}

			}
			s = "${s}</ul>"
			return s
		}
	}

	String processEachChild(node) {

		String s = "<li><a href='${node.@uri}'>${node.@label}</a>"

		Integer num = node.children().size()
		if (num > 0) {
			s = "${s}<ul>"
			node.children().each {
				if (node.@enabled == true){
					s = s + processEachChild(it)					
				}
			}
			s = "${s}</ul>"
		}

		s = "${s}</li>"
		return s
	}

}
