/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:26:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/31 14:01:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main ()
{
    int i;
	printf("Cas null\n");
	i = printf(0);
    printf("%d\n", i);
    i = ft_printf(0);
    printf("%d\n", i);
	i = printf("");
    printf("%d\n", i);
    i = ft_printf("");
    printf("%d\n", i);
    
    printf("\nCas sans specificateur\n");
    i = printf("bla %W bla %W");
    printf("\n%d\n", i);
    i = ft_printf("bla %W bla %W");
    printf("\n%d\n", i);
    i = printf("blabla%");
    printf("\n%d\n", i);
    i = ft_printf("blabla%");
    printf("\n%d\n", i);
	i = printf("blabla\n");
    printf("%d\n", i);
    i = ft_printf("blabla\n");
    printf("%d\n", i);
    
	printf("\ns\n");
	i = printf("Original: %s %s\n", "Je suis", "une patate.");
    printf("%d\n", i);
    i = ft_printf("Perso   : %s %s\n", "Je suis", "une patate.");
    printf("%d\n", i);
    
	printf("\n%\n");
	i = printf("test %m");
    printf("\n%d\n", i);
    i = ft_printf("test %m");
    printf("\n%d\n", i);
	i = printf("%m");
    printf("\n%d\n", i);
    i = ft_printf("%m");
    printf("\n%d\n", i);
	i = printf("% ");
    printf("\n%d\n", i);
    i = ft_printf("% ");
    printf("\n%d\n", i);
	i = printf("%");
    printf("\n%d\n", i);
    i = ft_printf("%");
    printf("\n%d\n", i);
	i = printf("Original: %%");
    printf("\n%d\n", i);
    i = ft_printf("Perso   : %%");
    printf("\n%d\n", i);
	i = printf("Original: %%\n");
    printf("%d\n", i);
    i = ft_printf("Perso   : %%\n");
    printf("%d\n", i);

	printf("\nc\n");
	i = printf("Original: %c\n", 'a');
    printf("%d\n", i);
    i = ft_printf("Perso   : %c\n", 'a');
    printf("%d\n", i);

	printf("\ni\n");
	i = printf("Original: %i\n", 010);
    printf("%d\n", i);
    i = ft_printf("Perso   : %i\n", 010);
    printf("%d\n", i);

	printf("\nd\n");
	i = printf("Original: %d\n", 0);
    printf("%d\n", i);
    i = ft_printf("Perso   : %d\n", 0);
    printf("%d\n", i);
    i = printf("Original: %d\n", 10);
    printf("%d\n", i);
    i = ft_printf("Perso   : %d\n", 10);
    printf("%d\n", i);

	printf("\np\n");
	i = printf("Original: %p\n", 9223372036854775807);
    printf("%d\n", i);
    i = ft_printf("Perso   : %p\n", 9223372036854775807);
    printf("%d\n", i);
    i = printf("Original: %p\n", -9223372036854775808);
    printf("%d\n", i);
    i = ft_printf("Perso   : %p\n", -9223372036854775808);
    printf("%d\n", i);
    return (0);
}