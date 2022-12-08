// ооп_урок3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Test
{
    int x;
public:
    Test() {  // конструктор по умолчанию - не принимает параметров.
        std::cout << "Constructor by defoult\n";
        x = 0;
    }
    Test(int a) {  // конструктор с параметром
        std::cout << "Constructor with parameters\n";
        x = a;
    }
    void Output(){
            std::cout << x << std::endl;
    }
    ~Test() {  // деструктор
        std::cout << "Destructor!\n";
    }
    
};

// Конструктор - каждый раз вызывается автоматически в момент создания любого объекта класса.
//  может принимать параметры, но не обязательно

int main1()
{
    int w = 15;
    Test one;  // первый объект нашего класса, хранит одно значение х
    one.Output();
    Test two(w);  // второй объект нашего класса, хранит другое значение х
    two.Output();

    return 0;
}

class Student {
    char* name;  // поля класса - указатель содержит адрес строки, который потом будет
                 // выделятся в динамической памяти. Если записать статически - можно
                 // написать char name[20], но тогда мы сразу должны зафиксировать кол-во
                 // символов, что не всегда оптимально. Для этого и нужна динамическая память,
                 // динамич память выделяется из кучи
    int age;     // поля класса
public:
    Student() {  // конструктор по умолчанию, изначально говорим - если создается объект
                 // типа Student и мы ничего туда не перадаем, будет вызыватся конструктор по
                 // умолчанию - объект будет пустой, динамич память выделяться не будет
        std::cout << "Constructor by defoult\n";
        name = nullptr;
        age = 0;
    }
    // Инициализаторы - альтернативный способ для Student()
    // Student(): name (nullptr), age(0) - сюда добавить
    // {         // инициализаторы - вместо того, чтобы писать это в теле классе.
    //           // инициализаторы обязательны, когда поле класса - это или константа,
    //           // или ссылка, или объект другого класса, у которого нет констр.по умолч.
    //   std::cout << "Constructor by defoult\n";
    //  // name = nullptr; - это убрать
    //  // age = 0; - это убрать
    // }
   
    Student(const char* Name, int Age) {  // const char* Name - указатель на константу, чтобы 
                                          // через указатель мы не смогли изменить то, что находится в строковом литерале
        std::cout << "Constructor with parameters\n";
        name = new char[strlen(Name) + 1];  // выделили динамическую память для массива name
                                            // оператор new возвращает адрес выделенного фрагмента
                                            // динамической памяти
        strcpy_s(name, strlen(Name) + 1, Name);  // в результате строка name будет содержать 
                                                 //  переданное имя Name
        age = Age;
    }
    /*
     Student(int Age) {  // если хотим для Age сделать отдельную ф-ию, другие поля надо занулить                                    
        std::cout << "Constructor with parameters\n";
        age = Age;  
        name = nullptr;  // зануляем другие поля, если это не написать - норм, но bad style
                         // либо не занулять, но в параметры кроме Age добавить Name (а этот Name
                         //  уже занулен в Student() - конструкторе по умолчанию
    }
    */

    void Output() {
        if (name == nullptr) {  // при выводе на экр пустого указателя char будет ошибка
            std::cout << "Empty object" << std::endl;
            return;
        }
        else {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
        }
    }
    ~Student() {
        delete[] name;
    }
};

int main2() {
    Student obj1("Oleg", 21);
    obj1.Output();

    /*Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };
    for (int i = 0; i < 2; i++)
    {
        mas[i].Output();
    }
    */
    return 0;
}



/*
    Реализуйте класс “Студент”. Необходимо хранить в переменных-членах класса:
    ФИО, дату рождения, контактный телефон, город, страну, 
    название учебного заведения, номер группы. Реализуйте функции-члены класса 
    для вывода данных, реализуйте аксессоры для доступа к отдельным 
    переменным-членам.
    Обязательно выделять память под ФИО студента и другие строки динамически,
    выделенную память необходимо освобождать в деструкторе.
*/
class Stud {
    char* name;
    int birth_day;
    int birth_month;
    int birth_year;
    long long tel;
    char* city;
   
public:
    Stud() {
       // std::cout << "Constructor by defoult\n";
        name = nullptr;
        birth_day = 0;
        birth_month = 0;
        birth_year = 0;
        tel = 0;
        city = nullptr;
       
    }
    Stud(const char* Name, int Birth_day, int Birth_month, int  Birth_year,
        long long Tel, const char* City) {
       // std::cout << "Constructor with parameters\n";
        name = new char[strlen(Name) + 1];  // выделили динамическую память для массива name
        strcpy_s(name, strlen(Name) + 1, Name);
        
        birth_day = Birth_day;
        birth_month = Birth_month;
        birth_year = Birth_year;
        tel = Tel;

        city = new char[strlen(City) + 1];  // выделили динамическую память для массива city
        strcpy_s(city, strlen(City) + 1, City);      
    }
 
    void Output() {
        if (name == nullptr || city == nullptr) {
            return;
        }
        else {
            std::cout << "Name: " << name << std::endl;
            std::cout << "birth day: " << birth_day << std::endl;
            std::cout << "birth month: " << birth_month << std::endl;
            std::cout << "birth year: " << birth_year << std::endl;
            std::cout << "Tel: " << tel << std::endl;
            std::cout << "City: " << city << std::endl;

        }
    }
    ~Stud() {
        delete[] name;
        delete[] city;
    }
};

int main3() {
    Stud obj("Ivan", 1, 9, 1994, 222333, "Odessa"); 
    obj.Output();

    return 0;
}

// для каждого поля класса выделяется своя память
// что, если мы хотим, чтобы какое-то поле класса было общим для всех объектов?
class Static
{
    double d;
    // const double Pi = 3.14;  // можем создать константу, и везде будет значение 3.14
    // Но в каждом объекте будет выделяться отдельная память на второе поле (поле  Pi)
    // а зачем выделять отдельную память, если это поле и так одинаковое, и мы хотим
    // чтобы это поле было общее для всех
    // напр, мы хотим сохдать общее поле, которое будет хранить кол-во созданных объектов
    // этого класса - тогда нам нужно статическое поле
public:
    static int numberOfObject;  // ключевое слово static для статического поля - создали стат.поле
    // на него не будет выделяться память в каждом объекте
    // память будет выделяться только когда создается класс - и будет хранится одна
    // ячейка памяти, где будет хранится содержимое этого поля
    // память на статическое поле выделяется сразу же при создании класса
    Static()                 // если мы хотим, чтобы поле содержало в себе кол-во
    {                        // существующих объектов этого класса
        d = 0;
        numberOfObject++;    // мы каждый раз, создавая объект этого класса
                             // должны значение этого поля увеличить на 1
    }
    void Output()
    {
        std::cout << d << std::endl;
    }
    int Get() const
    {
        return d;
    }
    void Set(int x)
    {
        d = x;
    }
    ~Static()  // в деструкторе соответственно уменьшаем на 1
    {
        numberOfObject--;
    }
};

int Static::numberOfObject = 0;  // статическое поле обязательно инициализировать
// :: - оператор разрешения области видимости


/*
 // если хотим написать функцию, напр Set, вне класса
    void Static::Set(int x)  // ф-ия НЕ является inline, когда она за пределами класса
    {
        d = x;
    }
*/

int main()
{                                                      // получить доступ к статич.полю можно,
    std::cout << Static::numberOfObject << std::endl;  // не создавая ни одного объекта класса
    Static obj;
    std::cout << Static::numberOfObject << std::endl;  // прослеживаем увеличение numberOfObject
    Static obj1;
    std::cout << Static::numberOfObject << std::endl;  // прослеживаем увеличение numberOfObject
    std::cout << obj1.numberOfObject << std::endl;
    {
        Static obj2;
        std::cout << Static::numberOfObject << std::endl;
    }
    std::cout << Static::numberOfObject << std::endl;

    //cout << Static::getNumber();
}


/*
 Конструкторы - спец методы, которые вызываются автоматически в момент создания объектов.
 Конструктор не имеет типа возвращаемого значения.
 Название конструктора всегда совпадает с названием класса.
 Конструктора можно перегружать.

 Деструктор - это спец метод, который автоматически вызывается перед уничтожением объекта.
 Деструкторы не перегружаются и не принимают параметров.
 Есть только один деструктор в классе, и имя деструктора совпадает с именем класса.
 Отработает деструктор столько раз, сколько есть объектов в классе (например созданные
  в мэйн объекты Test one; и Test two(w);  
*/










