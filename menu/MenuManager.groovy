package menu;

class MenuManager {
	
	static String getMenu(selectedLocale) {
		def config = new MenuConfigReader()
		def menu = config.readConfig(selectedLocale)
		def generator = new MenuGenerator()
		return generator.generateMenu(menu)
	}

	static void main(args) {
		getMenu(args[0])	
	}
}