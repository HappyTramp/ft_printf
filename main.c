/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 04:25:09 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/05 23:45:26 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main()
{
	int test = 42;

	/* ft_printf("% 63.108d%14p%03.i%106.19u%*.31s% 84.i%-122.78i%*c%32c%035.d" ,541752262,(void*)9603300624406182979lu,-346423835,2885566767u,-54,"0BG\td~l%",-1237089009,1122784046,-158,-7,66,1034929054); */
	/*    printf("% 63.108d%14p%03.i%106.19u%*.31s% 84.i%-122.78i%*c%32c%035.d" ,541752262,(void*)9603300624406182979lu,-346423835,2885566767u,-54,"0BG\td~l%",-1237089009,1122784046,-158,-7,66,1034929054); */
	/* printf("{%*3d}", 5, 0); */
	/* printf("{%*c}\n", -15, 0); */
	/* ft_printf("{%*c}\n", -15, 0); */
	/* ft_printf("%-72.170%%183.84x%174.189x%0+0'191.159s%107.*i%0#0+ 12.162c%#.38s%+'#  197.161i%'+#138.189s%#-0+'45.16X%' #+.71X%#-058.*d%0 +#137.30x%+16.145u%'23.72u" ,800115413,3199362515,"l$l%H6",-84514175,10,"fF(@Ju",795959316,";",3064849260,1535631011,-706426049,3490703638,3859198544,2268674351); */
	   /* printf("%#26.49p%'*.96c%-+-+ 37.180%%0#141.85i%  146.152X%91.199x%58.77i%0+'+'.140p%#67.141i%- 151.136d%101.187%%#*.56X%'+ 116.169x%69.74X%#0 #7.176%" ,16318453712790348322lu,46,814074579,1778514580,2425607191,1566569696,9615815307080556729lu,935162517,-447393454,385385973,3774990313,589711275); */
	/* ft_printf("%'+-+ 115.57d%#+0#115.33p%0--198.37x%77.42s%#+0+118.*X% 62.25i%0+#0#21.164i%+''157.91x%0 -0179.107c%++  70.100i%126.119d%118.182p%175.10i%''+-28.c%#167.153X" ,-812555527,8065328576609463455lu,2102650417,"Pw\tOVtwS",2307405425,1290938377,-351008211,3819076396,-51,-101089464,267730313,5298290595841494834lu,-911149367,-70,485455641); */
	/* printf("%#+0#115.33p\n", 54); */
	/* ft_printf("%#+0#115.33p\n", 54); */
	/* ft_printf("%"); */

	   /* printf("%"); */
	/* ft_printf("32 This is an int : %0d\n\n", 0); */
	/*    printf("32 This is an int : %0d\n\n", 0); */
	/* ft_printf("{%05.*d}\n", -15, 42); */
	/*    printf("{%05.*d}\n", -15, 42); */
	/* printf("%010p\n", 0x1); */
	/* ft_printf("%010p\n", 0x1); */
	/* ft_printf("%050 d\n", 500); */
	/*    printf("%050 d\n", 500); */
	/* ft_printf("%020.5s\n", "Hallo heimur"); */
	/*    printf("%020.5s\n", "Hallo heimur"); */
	/* ft_printf("bonjour%nyi", &test); */
	/* ft_printf("%hi\n", 32768); */
    /*    printf("%hi\n", 32768); */
	/* ft_printf("%.37ld", -22337203685477l); */


	ft_printf("[%]\n");
	   printf("[%]\n");
	ft_printf("[%5]\n");
	   printf("[%5]\n");
	ft_printf("[%05]\n");
	   printf("[%05]\n");


    /* ft_printf("char:                    %c\n", 'r'); */
    /* ft_printf("string:                  %s\n", "bonjour"); */
    /* ft_printf("pointer:                 %p\n", &test); */
    /* ft_printf("int:                     %d or %i\n", 45, 54); */
    /* ft_printf("uint:                    %u\n", 1 << 31); */
    /* ft_printf("hex lower:               %x\n", 0xabcf012); */
    /* ft_printf("hex upper:               %X\n", 0xabcf012); */
    /* ft_printf("percent:                 %%\n"); */
	/* ft_printf("multiple stuff:          %d %u %d %x %d\n", 1, -2, 3, 0xa, 5); */
    /*  */
	/* ft_printf("precision                |%.9d|\n", 43); */
	/*    printf("precision                |%.9d|\n", 43); */
	/* ft_printf("string precision         |%.9s|\n", "jesuisbonjourbonjour"); */
	/*    printf("string precision         |%.9s|\n", "jesuisbonjourbonjour"); */
	/* ft_printf("min width                |%9d|\n", 43); */
	/*    printf("min width                |%9d|\n", 43); */
	/* ft_printf("zero padding             |%09d|\n", 43); */
	/*    printf("zero padding             |%09d|\n", 43); */
	/* ft_printf("left adjusted            |%-9d|\n", 43); */
	/*    printf("left adjusted            |%-9d|\n", 43); */
	/* ft_printf("string padding           |%9s|\n", "bon"); */
	/*    printf("string padding           |%9s|\n", "bon"); */
    /*  */
	/* ft_printf("width wildcard           |%*d|\n", 5, 43); */
	/*    printf("width wildcard           |%*d|\n", 5, 43); */
	/* ft_printf("precision wildcard       |%.*d|\n", 5, 43); */
	/*    printf("precision wildcard       |%.*d|\n", 5, 43); */
	/* ft_printf("precision/width wildcard |%*.*d|\n", 5, 3, 43); */
	/*    printf("precision/width wildcard |%*.*d|\n", 5, 3, 43); */
	/* ft_printf("left adjusted            |%*d|\n", -5, 43); */
	/*    printf("left adjusted            |%*d|\n", -5, 43); */
    /*  */
	/* ft_printf("overwrite                |%*3d|\n", 5, 43); */
	/*    printf("overwrite                |%*3d|\n", 5, 43); */
	/* ft_printf("overwrite neg            |%*-1d|\n", 0, 43); */
	/*    printf("overwrite neg            |%*-1d|\n", 0, 43); */
    /*  */
    /* ft_printf("pointer field width      |%15p|\n", &test); */
    /*    printf("pointer field width      |%15p|\n", &test); */
    /* ft_printf("pointer precision        |%.15p|\n", &test); */
    /*    printf("pointer precision        |%.15p|\n", &test); */
    /* ft_printf("pointer precision/width  |%20.15p|\n", &test); */
    /*    printf("pointer precision/width  |%20.15p|\n", &test); */
    return 0;
}
