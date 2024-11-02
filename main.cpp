//dev branch

#include <iostream>
#include <string>

//collections
#include <map>
#include <vector>


using namespace std;

enum Category
{
    BOOK,
    MOVIE,
    MUSIC
};

class CategoryService
{
private:
    //Static Flow
    static uint64_t _id;

    //Basic
    map<Category, map<int, string>> _categories;
public:
    CategoryService() = default;
    CategoryService(Category category, string category_name)
    {
        setCategory(category, category_name);
    }
    string getCategoryName(Category category)
    {
        return _categories[category].begin()->second;
    }
    int getCategoryValue(Category category)
    {
        return _categories[category].begin()->first;
    }
    void setCategory(Category category, string category_name)
    {
        pair<int, string> category_pair = make_pair(_id++, category_name);
        _categories[category].insert(category_pair);
    }
};

uint64_t CategoryService::_id = 0;


class Item abstract
{
protected:
    string _name;
public:
    virtual void print() = 0;
};

class Book : public Item
{
public:
    Book(string name)
    {
        _name = name;
    }
    void print() override
    {
        cout << "The Book: \"" << _name << "\"" << endl;
    }
};

class Movie : public Item
{
public:
    Movie(string name)
    {
        _name = name;
    }
    void print() override
    {
        cout << "The Movie: \"" << _name << "\"" << endl;
    }
};

class Music : public Item
{
public:
    Music(string name)
    {
        _name = name;
    }
    void print() override
    {
        cout << "The Music: \"" << _name << "\"" << endl;
    }
};

int main()
{
    CategoryService categoryService;
    map<Category, vector<Item*>> collection;

    categoryService.setCategory(BOOK, "Book");
    categoryService.setCategory(MOVIE, "Movie");
    categoryService.setCategory(MUSIC, "Music");

    collection[BOOK].push_back(new Book("The Lord of the Rings"));
    collection[MOVIE].push_back(new Movie("The Lord of the Rings"));
    collection[MUSIC].push_back(new Music("The Lord of the Rings"));

    for (auto& category : collection)
    {
        cout << "Category: " << categoryService.getCategoryName(category.first) << endl;
        for (auto& item : category.second)
        {
            item->print();
        }
    }
    return 0;
}