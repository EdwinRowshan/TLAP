
class automobile {
public:
    automobile();
    automobile(string manufacturer, string model, int year);
    string getManufacturer();
    string getModel();
    int getYear();
    void setManufacturer(string manufacturer);
    void setModel(string model);
    void setYear(int year);
    void description();
    int age(int currentYear);
private:
    string _manufacturer;
    string _model;
    int _year;
};

void automobile::setManufacturer(string manufacturer) {
    _manufacturer = manufacturer;
}

void automobile::setModel(string model) {
    _model = model;
}

void automobile::setYear(int year) {
    _year = year;
}

automobile::automobile() {
    setManufacturer("");
    setModel("");
    setYear(-1);
}

automobile::automobile(string manufacturer, string model, int year) {
    setManufacturer(manufacturer);
    setYear(year);
    setModel(model);
}

string automobile::getManufacturer() {
    return _manufacturer;
}

string automobile::getModel() {
    return _model;
}

int automobile::getYear() {
    return _year;
}

void automobile::description() {
    cout << getManufacturer() << " " << getModel() << " " << getYear() << endl;
}

int automobile::age(int currentYear) {
    return currentYear - _year;
}

int main() {
    automobile honda = automobile("Honda", "Accord", 2007);
    honda.description();
    cout << honda.age(2022);
}
