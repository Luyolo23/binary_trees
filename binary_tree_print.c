#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_tree - Stores recursively each level in an array of strings
 *
 * @node: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buffer: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_tree(const binary_tree_t *node, int offset, int depth, char **buffer)
{
    char buffer_node[6];
    int node_width, left_offset, right_offset, is_left_child, i;

    if (!node)
        return (0);
    is_left_child = (node->parent && node->parent->left == node);
    node_width = sprintf(buffer_node, "(%03d)", node->n);
    left_offset = print_tree(node->left, offset, depth + 1, buffer);
    right_offset = print_tree(node->right, offset + left_offset + node_width, depth + 1, buffer);
    for (i = 0; i < node_width; i++)
        buffer[depth][offset + left_offset + i] = buffer_node[i];
    if (depth && is_left_child)
    {
        for (i = 0; i < node_width + right_offset; i++)
            buffer[depth - 1][offset + left_offset + node_width / 2 + i] = '-';
        buffer[depth - 1][offset + left_offset + node_width / 2] = '.';
    }
    else if (depth && !is_left_child)
    {
        for (i = 0; i < left_offset + node_width; i++)
            buffer[depth - 1][offset - node_width / 2 + i] = '-';
        buffer[depth - 1][offset + left_offset + node_width / 2] = '.';
    }
    return (left_offset + node_width + right_offset);
}

/**
 * calculate_height - Measures the height of a binary tree
 *
 * @node: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t calculate_height(const binary_tree_t *node)
{
    size_t left_height;
    size_t right_height;

    left_height = node->left ? 1 + calculate_height(node->left) : 0;
    right_height = node->right ? 1 + calculate_height(node->right) : 0;
    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @node: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *node)
{
    char **print_buffer;
    size_t tree_height, i, j;

    if (!node)
        return;
    tree_height = calculate_height(node);
    print_buffer = malloc(sizeof(*print_buffer) * (tree_height + 1));
    if (!print_buffer)
        return;
    for (i = 0; i < tree_height + 1; i++)
    {
        print_buffer[i] = malloc(sizeof(**print_buffer) * 255);
        if (!print_buffer[i])
            return;
        memset(print_buffer[i], 32, 255);
    }
    print_tree(node, 0, 0, print_buffer);
    for (i = 0; i < tree_height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (print_buffer[i][j] != ' ')
                break;
            print_buffer[i][j] = '\0';
        }
        printf("%s\n", print_buffer[i]);
        free(print_buffer[i]);
    }
    free(print_buffer);
}

