#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Tree
{
private:

	class TreeNode
	{
	public:
		string data;
		vector<TreeNode *> children;

		TreeNode(string d)
		{
			this->data = d;
		}
	};

	TreeNode *root;

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// to be implemented
	}

	void show() // display the tree node in a line
	{
		if (root != NULL)
		{
			queue<TreeNode *> q;
			q.push(root);

			TreeNode *tmp = NULL;

			while (!q.empty())
			{
				tmp = q.front();
				q.pop();

				cout << tmp->data << endl;
				vector<TreeNode *> &cld = tmp->children;

				int k = 0;
				while (k != cld.size())
				{
					q.push(cld[k]);
					k++;
				}
			}
		}
	}

	void addRoot(string d)
	{
		if (root == NULL)
		{
			root = new TreeNode(d);
		}
		else
		{
			// exception
		}
	}

	void addChild(string d, string parent)
	{
		TreeNode *tmp = NULL;
		TreeNode *parentPtr = NULL;

		queue<TreeNode *> q;

		q.push(root);
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();

			if (tmp->data == parent)
			{
				parentPtr = tmp;
				break;
			}
			else
			{
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					q.push(*p);
				}
			}
		}
		if (parentPtr != NULL)
		{
			tmp = new TreeNode(d);
			parentPtr->children.push_back(tmp);
		}
		else
		{
			throw 0;
		}
	}

};

int main()
{
	Tree t;

	t.addRoot("D:");
	t.addChild("PF", "D:");
	t.addChild("OOP", "D:");
	t.addChild("Quiz", "PF");
	t.addChild("Project", "PF");
	t.addChild("DSA", "D:");
	t.addChild("Marks", "DSA");
	//t.addChild("TTTTT", "Marks");
	//t.addChild("UUUUT", "D:");

	t.show(); // Unformatted output of a tree
	cout << endl;
	system("pause");
	return 0;
}
