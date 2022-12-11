static void    wait_pipes(int *pids, size_t size)
{
    size_t    count;
    int    status;
    int    ret;
    int should_stop;

    while (1)
    {
        should_stop = 1;
        count = 0;
        while (count < size)
        {
            if (pids[count] == -1)
            {
                count++;
                continue;
            }
            should_stop = 0;
            ret = waitpid(pids[count], &status, WNOHANG | WUNTRACED);
            if (ret < 0)
            {
                perror("wait");
                continue;
            }
            else if (ret > 0)
            {
                pids[count] = -1;
                if (WIFEXITED(status))
                    exit_cmd = WEXITSTATUS(status);
            }
            count ++;
        }

        if (should_stop)
            return;
    }
}