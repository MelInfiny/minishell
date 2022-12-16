/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:18:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 12:00:26 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int      g_redir(t_redir *redir, int status)
{
        int     infile;

        infile = -1;
        if (status)
        {
                ft_heredoc("/tmp/heredoc", redir->file);
                infile = open("/tmp/heredoc", O_RDONLY);
        }
        else
                infile = open(redir->file, O_RDONLY);
        return (infile);
}

static int      d_redir(char *file, int status)
{
        int     outfile;

        if (status)
                outfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
        else
                outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        return (outfile);
}

static int      ft_redirect_in(t_node *node)
{
        t_redir *redir;
        t_list  *r;
        int             res;

        res = 0;
        r = node->redir;
        while (r)
        {
                redir = r->content;
                if (redir->type == 1)
                        res = g_redir(redir, 0);
                if (redir->type == 11)
                        res = g_redir(redir, 1);
                if (res < 0)
                {
                        perror(redir->file);
                        return (-1);
                }
                r = r->next;
        }
        if (res > 0 && dup2(res, STDIN_FILENO) == -1)
                return (-1);
        if (res != 0)
        {
                close(res);
                return (1);
        }
        return (0);
}

static int      ft_redirect_out(t_node *node)
{
        t_redir *redir;
        t_list  *r;
        int             res;

        res = 0;
        r = node->redir;
        while (r)
        {
                redir = r->content;
                if (redir->type == 2)
                        res = d_redir(redir->file, 0);
                if (redir->type == 22)
                        res = d_redir(redir->file, 1);
                if (res < 0)
                {
                        perror(redir->file);
                        return (-1);
                }
                r = r->next;
        }
        if (res > 0 && dup2(res, STDOUT_FILENO) == -1)
                return (-1);
        if (res != 0)
        {
                close(res);
                return (1);
        }
        return (0);
}

int     ms_redir(t_node *node)
{
        int             res;

        res = -1;
        if (ft_redirect_in(node) < 0)
                return (-1);
        else
                res ++;
        if (ft_redirect_out(node) < 0)
                return (-1);
        else
                res +=2;
        return (res);
}

