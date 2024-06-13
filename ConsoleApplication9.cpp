#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//flyweight
class TreeType {
private:
	string name;
	string color;
	string texture;
public:
	TreeType(string name, string color, string texture) {
		this->color = color;
		this->name = name;
		this->texture = texture;
	}

	void draw(int x, int y) {
		cout << "Draw " << color << " " << name << " " << texture << " texture at (" << x << "," << y << ")" << endl;
	}

	string getName() {
		return name;
	}

	string getColor() {
		return color;
	}

	string getTexture() {
		return texture;
	}

};

class TreeFactory {
private:
	static vector <TreeType*> TreeTypes;
public:
	static TreeType* getTreeType(string name, string color, string texture) {
		for (int i = 0; i < TreeTypes.size(); i++) {
			if (TreeTypes[i]->getName() == name &&
				TreeTypes[i]->getColor() == color &&
				TreeTypes[i]->getTexture() == texture)
			{
				cout << "already exist " << endl;
				return TreeTypes[i];
			}
		}
		cout << "create new" << endl;
		TreeType* type = new TreeType(name, color, texture);
		TreeTypes.push_back(type);
		return new TreeType(name, color, texture);
	}
};

vector <TreeType*> TreeFactory::TreeTypes;

class Tree {
private:
	int x, y;
	TreeType* type;
public:
	Tree(int x, int y, TreeType* type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}

	void draw() {
		type->draw(x, y);
	}
};

class Forest {
private:
	vector <Tree> trees;
public:
	void plantTree(int x, int y, string name, string color, string texture) {
		TreeType* type = TreeFactory::getTreeType(name, color, texture);
		Tree tree(x, y, type);
		trees.push_back(tree);
	}

	void draw() {
		for (auto tree : trees) {
			tree.draw();
		}
	}

};




int main()
{
	Forest f1;
	f1.plantTree(10, 20, "kedr", "green", "sewqeq");
	f1.plantTree(30, 20, "kedr", "yello", "sewqeq");
	f1.draw();

}