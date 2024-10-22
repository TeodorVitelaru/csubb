package model;

public abstract class Task {
    private String taskId;
    private String description;

    public String getTaskId() {
        return taskId;
    }

    public String getDescription() {
        return description;
    }

    public Task(String taskId, String description) {
        this.taskId = taskId;
        this.description = description;
    }

    @Override
    public String toString() {
        return "Task [taskId=" + taskId + ", description=" + description + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
        {
            return true;
        }
        if(obj == null || this.getClass() != obj.getClass())
        {
            return false;
        }
        Task task = (Task) obj;
        return this.taskId.equals(task.taskId);
    }

}
