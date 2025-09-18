class TaskManager {

    HashMap<Integer, Integer> tasksPriority = new HashMap<>();
    HashMap<Integer, Integer> taskIdUserIdMap = new HashMap<>();
    TreeMap<Integer, TreeSet<Integer>> priorityMap = new TreeMap<>();
    public TaskManager(List<List<Integer>> tasks) {
        for (List<Integer> task : tasks) {
            int userId = task.get(0);
            int taskId = task.get(1);
            int priority = task.get(2);
            add(userId, taskId, priority);
        }
    }

    public void add(int userId, int taskId, int priority) {
        taskIdUserIdMap.put(taskId, userId);
        tasksPriority.put(taskId, priority);
        TreeSet<Integer> taskIdSet;
        if (priorityMap.containsKey(priority)) {
            taskIdSet = priorityMap.get(priority);
        } else {
            taskIdSet = new TreeSet<>();
        }
        taskIdSet.add(taskId);
        priorityMap.put(priority, taskIdSet);
    }

    public void edit(int taskId, int newPriority) {
                int prevPriority = tasksPriority.get(taskId);
        tasksPriority.put(taskId, newPriority);
        TreeSet<Integer> prevTaskIdSet = priorityMap.get(prevPriority);
        prevTaskIdSet.remove(taskId);
        if (prevTaskIdSet.isEmpty()) {
            priorityMap.remove(prevPriority);
        } 
        TreeSet<Integer> newTaskIdSet;
        if (priorityMap.containsKey(newPriority)) {
            newTaskIdSet = priorityMap.get(newPriority);
        } else {
            newTaskIdSet = new TreeSet<>();
        }
        newTaskIdSet.add(taskId);
        priorityMap.put(newPriority, newTaskIdSet);
    }

    public void rmv(int taskId) {
        int priority = tasksPriority.get(taskId);
        TreeSet<Integer> taskIdSet = priorityMap.get(priority);
        taskIdSet.remove(taskId);
        if (taskIdSet.isEmpty()) {
            priorityMap.remove(priority);
        } else {
            priorityMap.put(priority, taskIdSet);
        }
        tasksPriority.remove(taskId);
        taskIdUserIdMap.remove(taskId);
    }

    public int execTop() {
        if(priorityMap.isEmpty()) {
            return -1;
        }
        TreeSet<Integer> taskIdSet = priorityMap.lastEntry().getValue();
        int taskId = taskIdSet.last();
        int userId = taskIdUserIdMap.get(taskId);
        rmv(taskId);

        return userId;
    }
}

