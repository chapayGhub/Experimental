package menu;

class MenuConfigReader {

	Object readConfig(selectedLocale) {
		return new XmlSlurper().parse("menu-defs_${selectedLocale}.xml")
	}
}