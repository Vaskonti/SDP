
#ifndef OOP_2022_TASKS_QUADRATICEQUATION_H
#define OOP_2022_TASKS_QUADRATICEQUATION_H
class QuadraticEquation {
private:
    float A;
    float B;
    float C;
    void solveLinear();
public:
    QuadraticEquation();
    QuadraticEquation(const float A, const float B, const float C);
    const float getA() const;
    const float getB() const;
    const float getC() const;

    void setA(const float A);
    void setB(const float B);
    void setC(const float C);

    void solve();

};
#endif //OOP_2022_TASKS_QUADRATICEQUATION_H
