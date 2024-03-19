//You are given an array of CPU tasks, each represented by letters A to Z, 
//and a cooling time, n. Each cycle or interval allows the completion of one task.
//Tasks can be completed in any order, but there's a constraint: 
//identical tasks must be separated by at least n intervals due to cooling time.
//
//​Return the minimum number of intervals required to complete all tasks.

#include <vector>
#include <map>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n)
    {
        std::map<char, int> taskCount;
        std::map<char, int> taskCooldown;
        char priorityTask;
        int hightestCount = 0;
        int cycles = 0;
        int tasksLeft = 0;

        for (char task : tasks)
        {
            taskCount[task]++;
            if (taskCount[task] > hightestCount) {
                priorityTask = task;
                hightestCount = taskCount[task];
            }
            taskCooldown[task] = 0;
            tasksLeft++;
        }

        while (tasksLeft > 0)
        {
            if (taskCooldown[priorityTask] <= 0)
            {
                taskCount[priorityTask]--;
                hightestCount = 0;
                taskCooldown[priorityTask] = n + 1;
                tasksLeft--;
            }
            else
            {
                for (auto& task : taskCount)
                {
                    if (task.second > 0 && taskCooldown[task.first] <= 0)
                    {
                        task.second--;
                        taskCooldown[task.first] = n + 1;
                        tasksLeft--;
                        break;
                    }
                }
            }

            for (auto& cd : taskCooldown)
            {
                cd.second--;
                if (cd.second <= 0 && taskCount[cd.first] > hightestCount)
                {
                    priorityTask = cd.first;
                    hightestCount = taskCount[cd.first];
                }
            }
            cycles++;
        }

        return cycles;
    }
};