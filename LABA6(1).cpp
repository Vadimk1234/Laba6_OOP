#include <iostream>
#include <vector>
#include "ProjectManagement.h"

int main() {
    ProjectManager manager("Alexander (Manager)", 10000.0);
    manager.performWork();
    manager.reportStatus();

    std::cout << "Demonstrating unary operators (++ and --) on Budget:\n";
    Budget& mgrBudget = manager.getBudget();
    std::cout << "Initial limit: " << mgrBudget.getLimit() << "\n";

    ++mgrBudget;
    std::cout << "After prefix ++ (limit): " << mgrBudget.getLimit() << "\n";

    mgrBudget++;
    std::cout << "After postfix ++ (limit): " << mgrBudget.getLimit() << "\n";

    --mgrBudget;
    std::cout << "After prefix -- (limit): " << mgrBudget.getLimit() << "\n";

    mgrBudget--;
    std::cout << "After postfix -- (limit): " << mgrBudget.getLimit() << "\n";
    OfficeWorker worker1("John", 1000.0, "Developer");
    OfficeWorker worker2("Mary", 1000.0, "Tester");

    Team devTeam("Development Team", 3000.0);
    devTeam.addMember(&worker1);
    devTeam.addMember(&worker2);

    manager.assignTask(&devTeam, 2000.0);
    std::cout << "\n";

    std::vector<Employee*> projectParticipants;
    projectParticipants.push_back(&manager);
    projectParticipants.push_back(&devTeam);
    projectParticipants.push_back(&worker1);
    projectParticipants.push_back(&worker2);

    for (const auto* participant : projectParticipants) {
        participant->reportStatus();
    }

    std::cout << "\nExecuting tasks:\n";
    for (auto* participant : projectParticipants) {
        participant->performWork();
    }

    std::cout << "\n--- BUDGET STATUS AFTER WORK EXECUTION ---\n";
    for (const auto* participant : projectParticipants) {
        participant->reportStatus();
    }

    return 0;
}