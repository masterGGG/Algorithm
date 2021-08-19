#include <iostream>
#include <vector>

/*
猫狗队列 【题目】 宠物、狗和猫的类如下:
public class Pet { 
    private String type;
    public Pet(String type) { this.type = type; } 
    public String getPetType() { return this.type; } 
}

public class Dog extends Pet { public Dog() { super("dog"); } } 
public class Cat extends Pet { public Cat() { super("cat"); } }
实现一种狗猫队列的结构，要求如下: 
用户可以调用add方法将cat类或dog类的 实例放入队列中; 
用户可以调用pollAll方法，将队列中所有的实例按照进队列 的先后顺序依次弹出; 
用户可以调用pollDog方法，将队列中dog类的实例按照 进队列的先后顺序依次弹出; 
用户可以调用pollCat方法，将队列中cat类的实 例按照进队列的先后顺序依次弹出; 
用户可以调用isEmpty方法，检查队列中是 否还有dog或cat的实例; 
用户可以调用isDogEmpty方法，检查队列中是否有dog 类的实例; 
用户可以调用isCatEmpty方法，检查队列中是否有cat类的实例。
*/

const int DOG = 1;
const int CAT = 2;

class Pet { 
private:
    int type;

public:
    Pet(int t) { type = t; } 
    int getPetType() { return type; } 
}

class Cat : public Pet {
public:
    Cat() {
        super(CAT);
    }
}

class Dog : public Pet {
public:
    Dog() {
        super(DOG);
    }
}

class PetElement {
public:
    PetElement(Pet p, int pos) : pet(p),index(pos) {}
    GetPet() { return pet; }
    GetIdx() { return index; }
public:
    Pet pet;
    int index;
}