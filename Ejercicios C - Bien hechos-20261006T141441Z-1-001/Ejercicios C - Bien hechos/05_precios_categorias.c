/* Video 5 - Calculo de precios segun categorias
   Bazar de barrio: productos gold (10 euros) y silver (5 euros), con IVA
   general (21%) o reducido (10%). Calcular el precio sin IVA de cada uno.
   Precio sin IVA = precio con IVA / (1 + IVA en tanto por 1). */
#include <stdio.h>

int main()
{
    /* Precios de los productos (IVA incluido) */
    float gold = 10, silver = 5;
    /* Precios sin IVA */
    float gold_general, silver_general, gold_reducido, silver_reducido;
    /* IVA en tanto por 1 */
    float iva_general = 0.21, iva_reducido = 0.10;

    /* Calculo de los precios sin IVA (divisiones reales) */
    gold_general = gold / (1 + iva_general);
    silver_general = silver / (1 + iva_general);
    gold_reducido = gold / (1 + iva_reducido);
    silver_reducido = silver / (1 + iva_reducido);

    /* Resultados */
    printf("Productos con IVA general:\n");
    printf("  Productos gold: %.2f euros sin IVA\n", gold_general);
    printf("  Productos silver: %.2f euros sin IVA\n", silver_general);
    printf("Productos con IVA reducido:\n");
    printf("  Productos gold: %.2f euros sin IVA\n", gold_reducido);
    printf("  Productos silver: %.2f euros sin IVA\n", silver_reducido);

    /* Solucion alternativa mas corta: el calculo dentro del printf,
       sin variables intermedias:
    printf("  Productos gold: %.2f euros sin IVA\n", gold / (1 + iva_general));
    ... */

    return 0;
}
