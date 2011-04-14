package menu;

import java.util.Locale
import java.util.List

class Menu {
	
	String label
	String image
	String hoverImage;
	Boolean enabled
	Integer order
	//Locale locale
	def menuItems = []

	String toString() {
		return "Menu: ${label}, enabled=${enabled}";
	}
}