package menu;

class MenuItem {

	String label
	String uri
	String passThrough
	Boolean enabled
	Integer order

	String toString() {
		return "MenuItem: ${label}, ${uri}"
	}
}