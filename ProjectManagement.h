#pragma once
#ifndef PROJECT_MANAGEMENT_H
#define PROJECT_MANAGEMENT_H

#include <string>
#include <vector>

class Budget {
private:
    double totalLimit;
    double spentAmount;

public:
    Budget(double limit);
    double getLimit() const;
    double getSpentAmount() const;
    bool allocateFunds(double amount);
    void reset();

    Budget& operator++();
    Budget operator++(int);
    Budget& operator--();
    Budget operator--(int);
};

class Employee {
protected:
    std::string name;
    Budget budget;

public:
    Employee(const std::string& empName, double initialBudget);
    virtual ~Employee() = default;

    virtual void performWork() = 0;
    virtual void reportStatus() const;

    std::string getName() const;
    Budget& getBudget();
};

class OfficeWorker : public Employee {
private:
    std::string specialty;

public:
    OfficeWorker(const std::string& empName, double initialBudget, const std::string& spec);

    void performWork() override;
    void reportStatus() const override;
};

class Team : public Employee {
private:
    std::vector<Employee*> members;

public:
    Team(const std::string& teamName, double initialBudget);

    void addMember(Employee* member);
    void performWork() override;
    void reportStatus() const override;
};

class ProjectManager : public Employee {
private:
    std::vector<Employee*> subordinates;

public:
    ProjectManager(const std::string& managerName, double totalBudget);

    void assignTask(Employee* worker, double taskBudget);
    void performWork() override;
    void reportStatus() const override;
};

#endif // PROJECT_MANAGEMENT_H