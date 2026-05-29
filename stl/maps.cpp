#include <iostream>
#include <string>
#include <map>


int main_map() {
	std::map<int, std::string> objects{ { 1, "Cube"}, {2, "Sphere"}, {3, "Wall"}, {4, "player"} };

	// looping through a map
	for (std::pair<int, std::string> el : objects)
	{
		std::cout << el.first << " - " << el.second << '\n';
	}

	// adding to the map using the subscript op
	objects[5] = "car";
	objects[6] = "bank_building";
	// usin insert
	objects.insert({ 7, "vice_highway" });

	std::map<int, std::string>::const_iterator iter = objects.find(5);

	for (auto startIter = iter; iter != objects.end(); iter++)
	{
		std::cout << iter->first << " - " << iter->second << '\n';
	}

	return 0;
}