/* =============================================================================
 * regras_tabela.inc — GERADO por gerador/gerar_kernel.c. NÃO EDITE À MÃO.
 *
 * O que é: todas as regras de atualizar_ortografia() do motor, NA MESMA ORDEM,
 *          uma por linha:  R(tipo, "antigo", "novo", acento), seguida da linha no motor
 *            R_TEXTO    = substituir_texto            R_SUFIXOS  = atualizar_sufixos_e_enclises
 *            R_INICIO   = substituir_inicio_palavra   R_GERUNDIO = converter_infinitivo_lusitano_para_gerundio
 *            R_INTEIRA  = substituir_palavra_inteira
 *          acento = a conta "a regra acrescenta acento?" de substituir_inicio_palavra,
 *          feita aqui uma vez (no motor ela é feita em cada chamada).
 *          Os laços do motor (mesóclise, -has, zona invisível, nomes próprios, revisão)
 *          já estão abertos: cada volta do laço é uma linha. Os comentários do motor
 *          estão no mesmo lugar, para quem lê achar cada parte (1 a 12).
 * Por quê: o kernel percorre esta tabela com um índice e pula as regras que não
 *          podem casar no versículo, em vez de chamar as 5150 regras uma a uma.
 * Para mudar uma regra: mude no motor.biblia.c e rode o gerador (veja LEIAME.md).
 * Formato criado em 27/11/2026. Fonte: motor.biblia.c
 *          (SHA-256 do motor: DF46AC4D34CB59AE901864970E8F8626223E0A08877D55C4EC1CC489A2D6A891)
 * Regras: 5150 (texto 1273, início 1118, inteira 2757, sufixos 1, gerúndio 1).
 * ============================================================================= */

/* Assinatura (FNV-1a 64) do texto de substituir_texto, substituir_inicio_palavra e
   substituir_palavra_inteira no motor. biblia_kernel.c confere este valor. */
#define BK_GERADO_ASSINATURA_TROCAS 0xf3bd7e03ea0ee6c3ull
#define BK_GERADO_MAX_LINHA 8192
#define BK_GERADO_TOTAL_REGRAS 5150
#define BK_GERADO_SHA_MOTOR "DF46AC4D34CB59AE901864970E8F8626223E0A08877D55C4EC1CC489A2D6A891"

#ifdef R
// 1. Padroniza apóstrofo curvo UTF-8 (’) para apóstrofo simples (')
R(R_TEXTO, "\xE2\x80\x99", "'", 0) /* linha 697 */
// 2. Contrações antigas com apóstrofo (formas aglutinadas)
R(R_INICIO, "d'elle", "dele", 0) /* linha 700 */
R(R_INICIO, "D'elle", "Dele", 0) /* linha 700 */
R(R_INICIO, "d'ella", "dela", 0) /* linha 701 */
R(R_INICIO, "D'ella", "Dela", 0) /* linha 701 */
R(R_INICIO, "d'elles", "deles", 0) /* linha 702 */
R(R_INICIO, "D'elles", "Deles", 0) /* linha 702 */
R(R_INICIO, "d'ellas", "delas", 0) /* linha 703 */
R(R_INICIO, "D'ellas", "Delas", 0) /* linha 703 */
R(R_INICIO, "n'elle", "nele", 0) /* linha 704 */
R(R_INICIO, "N'elle", "Nele", 0) /* linha 704 */
R(R_INICIO, "n'ella", "nela", 0) /* linha 705 */
R(R_INICIO, "N'ella", "Nela", 0) /* linha 705 */
R(R_INICIO, "n'elles", "neles", 0) /* linha 706 */
R(R_INICIO, "N'elles", "Neles", 0) /* linha 706 */
R(R_INICIO, "n'ellas", "nelas", 0) /* linha 707 */
R(R_INICIO, "N'ellas", "Nelas", 0) /* linha 707 */
R(R_INICIO, "d'este", "deste", 0) /* linha 708 */
R(R_INICIO, "D'este", "Deste", 0) /* linha 708 */
R(R_INICIO, "d'esta", "desta", 0) /* linha 709 */
R(R_INICIO, "D'esta", "Desta", 0) /* linha 709 */
R(R_INICIO, "d'estes", "destes", 0) /* linha 710 */
R(R_INICIO, "d'estas", "destas", 0) /* linha 710 */
R(R_INICIO, "n'este", "neste", 0) /* linha 711 */
R(R_INICIO, "n'esta", "nesta", 0) /* linha 711 */
R(R_INICIO, "n'estes", "nestes", 0) /* linha 712 */
R(R_INICIO, "n'estas", "nestas", 0) /* linha 712 */
R(R_INICIO, "d'isto", "disto", 0) /* linha 713 */
R(R_INICIO, "n'isto", "nisto", 0) /* linha 713 */
R(R_INICIO, "d'isso", "disso", 0) /* linha 714 */
R(R_INICIO, "n'isso", "nisso", 0) /* linha 714 */
R(R_INICIO, "d'aquillo", "daquilo", 0) /* linha 715 */
R(R_INICIO, "n'aquillo", "naquilo", 0) /* linha 715 */
R(R_INICIO, "d'um", "dum", 0) /* linha 716 */
R(R_INICIO, "d'uma", "duma", 0) /* linha 716 */
R(R_INICIO, "d'uns", "duns", 0) /* linha 717 */
R(R_INICIO, "d'umas", "dumas", 0) /* linha 717 */
R(R_INICIO, "n'um", "num", 0) /* linha 718 */
R(R_INICIO, "n'uma", "numa", 0) /* linha 718 */
R(R_INICIO, "n'uns", "nuns", 0) /* linha 719 */
R(R_INICIO, "n'umas", "numas", 0) /* linha 719 */
R(R_INICIO, "d'aquelle", "daquele", 0) /* linha 720 */
R(R_INICIO, "d'aquella", "daquela", 0) /* linha 720 */
R(R_INICIO, "n'aquelle", "naquele", 0) /* linha 721 */
R(R_INICIO, "n'aquella", "naquela", 0) /* linha 721 */
R(R_INICIO, "aquell'outro", "aqueloutro", 0) /* linha 722 */
R(R_INICIO, "d'aqui", "daqui", 0) /* linha 723 */
R(R_INICIO, "d'alli", "dali", 0) /* linha 723 */
R(R_INICIO, "d'ali", "dali", 0) /* linha 724 */
R(R_INICIO, "d'onde", "donde", 0) /* linha 725 */
R(R_INICIO, "D'onde", "Donde", 0) /* linha 725 */
R(R_INICIO, "lh'o", "lho", 0) /* linha 726 */
R(R_INICIO, "lh'a", "lha", 0) /* linha 726 */
R(R_INICIO, "lh'os", "lhos", 0) /* linha 727 */
R(R_INICIO, "lh'as", "lhas", 0) /* linha 727 */
/* Contrações com maiúscula e outras que faltavam (antes: "N'aquelle" -> "Em aquele") */
R(R_INICIO, "N'aquelles", "Naqueles", 0) /* linha 730 */
R(R_INICIO, "N'aquellas", "Naquelas", 0) /* linha 730 */
R(R_INICIO, "N'aquelle", "Naquele", 0) /* linha 731 */
R(R_INICIO, "N'aquella", "Naquela", 0) /* linha 731 */
R(R_INICIO, "N'aquillo", "Naquilo", 0) /* linha 732 */
R(R_INICIO, "D'aquillo", "Daquilo", 0) /* linha 732 */
R(R_INICIO, "D'aquelle", "Daquele", 0) /* linha 733 */
R(R_INICIO, "D'aquella", "Daquela", 0) /* linha 733 */
R(R_INICIO, "D'aquelles", "Daqueles", 0) /* linha 734 */
R(R_INICIO, "D'aquellas", "Daquelas", 0) /* linha 734 */
R(R_INICIO, "d'aquelles", "daqueles", 0) /* linha 735 */
R(R_INICIO, "d'aquellas", "daquelas", 0) /* linha 735 */
R(R_INICIO, "n'aquelles", "naqueles", 0) /* linha 736 */
R(R_INICIO, "n'aquellas", "naquelas", 0) /* linha 736 */
R(R_INICIO, "N'isto", "Nisto", 0) /* linha 737 */
R(R_INICIO, "N'isso", "Nisso", 0) /* linha 737 */
R(R_INICIO, "D'isto", "Disto", 0) /* linha 738 */
R(R_INICIO, "D'isso", "Disso", 0) /* linha 738 */
R(R_INICIO, "N'este", "Neste", 0) /* linha 739 */
R(R_INICIO, "N'esta", "Nesta", 0) /* linha 739 */
R(R_INICIO, "N'estes", "Nestes", 0) /* linha 740 */
R(R_INICIO, "N'estas", "Nestas", 0) /* linha 740 */
R(R_INICIO, "N'esse", "Nesse", 0) /* linha 741 */
R(R_INICIO, "N'essa", "Nessa", 0) /* linha 741 */
R(R_INICIO, "n'esse", "nesse", 0) /* linha 742 */
R(R_INICIO, "n'essa", "nessa", 0) /* linha 742 */
R(R_INICIO, "n'esses", "nesses", 0) /* linha 743 */
R(R_INICIO, "n'essas", "nessas", 0) /* linha 743 */
R(R_INICIO, "d'esse", "desse", 0) /* linha 744 */
R(R_INICIO, "d'essa", "dessa", 0) /* linha 744 */
R(R_INICIO, "N'um", "Num", 0) /* linha 745 */
R(R_INICIO, "N'uma", "Numa", 0) /* linha 745 */
R(R_INICIO, "n'algum", "nalgum", 0) /* linha 746 */
R(R_INICIO, "n'alguma", "nalguma", 0) /* linha 746 */
R(R_INICIO, "n'alguns", "nalguns", 0) /* linha 747 */
R(R_INICIO, "n'algumas", "nalgumas", 0) /* linha 747 */
R(R_INICIO, "n'outro", "noutro", 0) /* linha 748 */
R(R_INICIO, "n'outra", "noutra", 0) /* linha 748 */
R(R_INICIO, "n'outros", "noutros", 0) /* linha 749 */
R(R_INICIO, "n'outras", "noutras", 0) /* linha 749 */
/* Pronome depois de hífen: "ataram-n'o" -> "ataram-no" (antes virava "ataram-em o") */
R(R_TEXTO, "-n'os", "-nos", 0) /* linha 751 */
R(R_TEXTO, "-n'as", "-nas", 0) /* linha 751 */
R(R_TEXTO, "-n'o", "-no", 0) /* linha 752 */
R(R_TEXTO, "-n'a", "-na", 0) /* linha 752 */
/* me/te + o/a: "m'o" -> "mo", "t'a" -> "ta" */
R(R_INICIO, "m'os", "mos", 0) /* linha 754 */
R(R_INICIO, "m'as", "mas", 0) /* linha 754 */
R(R_INICIO, "m'o", "mo", 0) /* linha 755 */
R(R_INICIO, "m'a", "ma", 0) /* linha 755 */
R(R_INICIO, "t'os", "tos", 0) /* linha 756 */
R(R_INICIO, "t'as", "tas", 0) /* linha 756 */
R(R_INICIO, "t'o", "to", 0) /* linha 757 */
R(R_INICIO, "t'a", "ta", 0) /* linha 757 */
R(R_INICIO, "d'", "de ", 0) /* linha 759 */
R(R_INICIO, "D'", "De ", 0) /* linha 760 */
R(R_INICIO, "n'", "em ", 0) /* linha 761 */
R(R_INICIO, "N'", "Em ", 0) /* linha 762 */
// 3. Crase antiga com acento agudo e locuções
R(R_TEXTO, " á ", " à ", 0) /* linha 765 */
R(R_TEXTO, " ás ", " às ", 0) /* linha 766 */
R(R_INICIO, "Á ", "À ", 0) /* linha 767 */
R(R_INICIO, "Ás ", "Às ", 0) /* linha 768 */
R(R_INICIO, "áquel", "àquel", 0) /* linha 769 */
R(R_INICIO, "Áquel", "Àquel", 0) /* linha 770 */
R(R_INICIO, "ámanhã", "amanhã", 0) /* linha 771 */
R(R_INICIO, "Ámanhã", "Amanhã", 0) /* linha 772 */
R(R_INICIO, "áparte", "à parte", 0) /* linha 773 */
R(R_INICIO, "áquem", "aquém", 0) /* linha 774 */
R(R_INICIO, "ácerca", "acerca", 0) /* linha 775 */
R(R_INICIO, "Ácerca", "Acerca", 0) /* linha 776 */
R(R_TEXTO, "afim de", "a fim de", 0) /* linha 777 */
// 4. Regras críticas ANTES da simplificação de consoantes dobradas
R(R_INICIO, "sabbado", "sábado", 1) /* linha 780 */
R(R_INICIO, "Sabbado", "Sábado", 1) /* linha 781 */
R(R_INICIO, "SABBADO", "SÁBADO", 1) /* linha 782 */
R(R_INICIO, "attrahi", "atraí", 0) /* linha 783 */
R(R_INICIO, "Attrahi", "Atraí", 0) /* linha 784 */
R(R_INICIO, "attrahe", "atrai", 0) /* linha 785 */
R(R_INICIO, "ressurg", "ressurg", 0) /* linha 786 */
R(R_INICIO, "resvall", "resval", 0) /* linha 787 */
// 5. Dígrafos antigos (Ph, Th, Y) e consoantes dobradas (maiúsculas e minúsculas)
R(R_TEXTO, "PH", "F", 0) /* linha 790 */
R(R_TEXTO, "Ph", "F", 0) /* linha 791 */
R(R_TEXTO, "ph", "f", 0) /* linha 792 */
R(R_TEXTO, "TH", "T", 0) /* linha 793 */
R(R_TEXTO, "Th", "T", 0) /* linha 794 */
R(R_TEXTO, "th", "t", 0) /* linha 795 */
R(R_TEXTO, "Y", "I", 0) /* linha 796 */
R(R_TEXTO, "y", "i", 0) /* linha 797 */
R(R_TEXTO, "ll", "l", 0) /* linha 799 */
R(R_TEXTO, "LL", "L", 0) /* linha 799 */
R(R_TEXTO, "mm", "m", 0) /* linha 800 */
R(R_TEXTO, "MM", "M", 0) /* linha 800 */
R(R_TEXTO, "nn", "n", 0) /* linha 801 */
R(R_TEXTO, "NN", "N", 0) /* linha 801 */
R(R_TEXTO, "ff", "f", 0) /* linha 802 */
R(R_TEXTO, "FF", "F", 0) /* linha 802 */
R(R_TEXTO, "pp", "p", 0) /* linha 803 */
R(R_TEXTO, "PP", "P", 0) /* linha 803 */
R(R_TEXTO, "tt", "t", 0) /* linha 804 */
R(R_TEXTO, "TT", "T", 0) /* linha 804 */
R(R_TEXTO, "cc", "c", 0) /* linha 805 */
R(R_TEXTO, "CC", "C", 0) /* linha 805 */
R(R_TEXTO, "dd", "d", 0) /* linha 806 */
R(R_TEXTO, "DD", "D", 0) /* linha 806 */
R(R_TEXTO, "bb", "b", 0) /* linha 807 */
R(R_TEXTO, "BB", "B", 0) /* linha 807 */
R(R_TEXTO, "gg", "g", 0) /* linha 808 */
R(R_TEXTO, "GG", "G", 0) /* linha 808 */
// 6. Grupos consonantais mudos (cç, ct, pt, mn, gm, ch -> c/qu)
R(R_TEXTO, "cç", "ç", 0) /* linha 811 */
R(R_INICIO, "CHRIST", "CRIST", 0) /* linha 812 */
R(R_INICIO, "Christ", "Crist", 0) /* linha 813 */
R(R_INICIO, "christ", "crist", 0) /* linha 814 */
R(R_INICIO, "chronic", "crônic", 0) /* linha 815 */
R(R_INICIO, "archanjo", "arcanjo", 0) /* linha 816 */
R(R_INICIO, "architecto", "arquiteto", 0) /* linha 817 */
R(R_INICIO, "sepulchr", "sepulcr", 0) /* linha 818 */
R(R_INICIO, "patriarch", "patriarc", 0) /* linha 819 */
R(R_INICIO, "tetrarch", "tetrarc", 0) /* linha 820 */
R(R_INICIO, "eunuch", "eunuc", 0) /* linha 821 */
R(R_INICIO, "mechanic", "mecânic", 0) /* linha 822 */
R(R_INICIO, "paschoa", "Páscoa", 0) /* linha 823 */
R(R_INICIO, "Paschoa", "Páscoa", 0) /* linha 824 */
R(R_INICIO, "chalcedonia", "calcedônia", 0) /* linha 825 */
R(R_INICIO, "Chaldea", "Caldeia", 0) /* linha 826 */
R(R_INICIO, "chaldeo", "caldeu", 0) /* linha 827 */
R(R_TEXTO, "fruct", "frut", 0) /* linha 829 */
R(R_TEXTO, "Fruct", "Frut", 0) /* linha 830 */
R(R_INICIO, "sanct", "sant", 0) /* linha 831 */
R(R_INICIO, "Sanct", "Sant", 0) /* linha 832 */
R(R_INICIO, "SANCT", "SANT", 0) /* linha 833 */
R(R_INICIO, "afflict", "aflit", 0) /* linha 834 */
R(R_INICIO, "victima", "vítima", 1) /* linha 835 */
R(R_INICIO, "victoria", "vitória", 1) /* linha 836 */
R(R_INICIO, "victorios", "vitorios", 0) /* linha 837 */
R(R_INICIO, "luct", "lut", 0) /* linha 838 */
R(R_INICIO, "Luct", "Lut", 0) /* linha 839 */
R(R_INICIO, "nocturn", "noturn", 0) /* linha 840 */
R(R_INICIO, "delict", "delit", 0) /* linha 841 */
R(R_INICIO, "edict", "édit", 1) /* linha 842 */
R(R_INICIO, "distinct", "distint", 0) /* linha 843 */
R(R_INICIO, "extinct", "extint", 0) /* linha 844 */
R(R_INICIO, "contract", "contrat", 0) /* linha 845 */
R(R_INICIO, "detractor", "detrator", 0) /* linha 846 */
R(R_INICIO, "predilect", "predilet", 0) /* linha 847 */
R(R_INICIO, "rectidão", "retidão", 0) /* linha 848 */
R(R_INICIO, "rectamente", "retamente", 0) /* linha 849 */
R(R_INICIO, "rectaguarda", "retaguarda", 0) /* linha 850 */
R(R_INICIO, "object", "objet", 0) /* linha 851 */
R(R_INICIO, "project", "projet", 0) /* linha 852 */
R(R_INICIO, "Project", "Projet", 0) /* linha 853 */
R(R_INICIO, "product", "produt", 0) /* linha 854 */
R(R_INICIO, "exact", "exat", 0) /* linha 855 */
R(R_INICIO, "acto", "ato", 0) /* linha 856 */
R(R_INICIO, "actos", "atos", 0) /* linha 857 */
R(R_TEXTO, "escript", "escrit", 0) /* linha 858 */
R(R_TEXTO, "Escript", "Escrit", 0) /* linha 859 */
R(R_INICIO, "captiv", "cativ", 0) /* linha 860 */
R(R_INICIO, "prompt", "pront", 0) /* linha 861 */
R(R_INICIO, "assump", "assun", 0) /* linha 862 */
R(R_INICIO, "presump", "presun", 0) /* linha 863 */
R(R_INICIO, "redemp", "reden", 0) /* linha 864 */
R(R_INICIO, "Redemp", "Reden", 0) /* linha 865 */
R(R_INICIO, "exempt", "isent", 0) /* linha 866 */
R(R_INICIO, "bapt", "bat", 0) /* linha 867 */
R(R_INICIO, "Bapt", "Bat", 0) /* linha 868 */
R(R_INICIO, "sceptr", "cetr", 0) /* linha 869 */
R(R_INICIO, "inscrip", "inscri", 0) /* linha 870 */
R(R_INICIO, "descrip", "descri", 0) /* linha 871 */
R(R_INICIO, "prescrip", "prescri", 0) /* linha 872 */
R(R_INICIO, "augment", "aument", 0) /* linha 873 */
R(R_INICIO, "Augment", "Aument", 0) /* linha 874 */
R(R_INICIO, "condemn", "conden", 0) /* linha 875 */
R(R_INICIO, "Condemn", "Conden", 0) /* linha 876 */
R(R_INICIO, "solemn", "solen", 0) /* linha 877 */
R(R_INICIO, "Solemn", "Solen", 0) /* linha 878 */
R(R_INICIO, "damn", "dan", 0) /* linha 879 */
R(R_INICIO, "somno", "sono", 0) /* linha 880 */
R(R_INICIO, "hymno", "hino", 0) /* linha 881 */
R(R_INICIO, "alumno", "aluno", 0) /* linha 882 */
R(R_INICIO, "calumni", "calúni", 1) /* linha 883 */
/* calúnia(s) */
R(R_INICIO, "calumni", "caluni", 0) /* linha 884 */
/* caluniar, caluniador... */
R(R_INICIO, "columna", "coluna", 0) /* linha 885 */
R(R_INICIO, "Omnipotente", "Onipotente", 0) /* linha 886 */
R(R_INICIO, "omnipotente", "onipotente", 0) /* linha 887 */
R(R_INICIO, "signa", "sina", 0) /* linha 888 */
R(R_INICIO, "signal", "sinal", 0) /* linha 889 */
R(R_INICIO, "assign", "assin", 0) /* linha 890 */
R(R_INICIO, "Assign", "Assin", 0) /* linha 891 */
R(R_INICIO, "psalm", "salm", 0) /* linha 892 */
R(R_INICIO, "Psalm", "Salm", 0) /* linha 893 */
R(R_INICIO, "sciencia", "ciência", 1) /* linha 894 */
// 7. Aplica regras morfológicas de sufixos, ênclises, mesóclises e compostos com hífen
/* "eil-o" -> "ei-lo" (sem acento); precisa vir antes das ênclises */
R(R_INTEIRA, "eil-o", "ei-lo", 0) /* linha 898 */
R(R_INTEIRA, "Eil-o", "Ei-lo", 0) /* linha 898 */
R(R_INTEIRA, "eil-a", "ei-la", 0) /* linha 899 */
R(R_INTEIRA, "Eil-a", "Ei-la", 0) /* linha 899 */
R(R_INTEIRA, "eil-os", "ei-los", 0) /* linha 900 */
R(R_INTEIRA, "Eil-os", "Ei-los", 0) /* linha 900 */
R(R_INTEIRA, "eil-as", "ei-las", 0) /* linha 901 */
R(R_INTEIRA, "Eil-as", "Ei-las", 0) /* linha 901 */
R(R_SUFIXOS, "", "", 0) /* linha 903 */
// 8. Flexões irregulares e vocabulário histórico de 1911
R(R_TEXTO, " he ", " é ", 0) /* linha 906 */
R(R_INICIO, "He ", "É ", 0) /* linha 907 */
R(R_TEXTO, " ha ", " há ", 0) /* linha 908 */
R(R_TEXTO, " ha,", " há,", 0) /* linha 908 */
R(R_INICIO, "Ha ", "Há ", 0) /* linha 908 */
R(R_INICIO, "hum ", "um ", 0) /* linha 909 */
R(R_INICIO, "huma ", "uma ", 0) /* linha 910 */
R(R_INICIO, "huns ", "uns ", 0) /* linha 911 */
R(R_INICIO, "humas ", "umas ", 0) /* linha 912 */
R(R_INICIO, "hontem", "ontem", 0) /* linha 913 */
R(R_INICIO, "Hontem", "Ontem", 0) /* linha 914 */
R(R_INICIO, "hombro", "ombro", 0) /* linha 915 */
R(R_INICIO, "hombreira", "ombreira", 0) /* linha 916 */
R(R_INICIO, "humidade", "umidade", 0) /* linha 917 */
R(R_INICIO, "humedecem", "umedecem", 0) /* linha 918 */
R(R_INICIO, "vehemen", "veemen", 0) /* linha 919 */
R(R_INICIO, "cohorte", "coorte", 0) /* linha 920 */
R(R_INICIO, "creou", "criou", 0) /* linha 922 */
R(R_INICIO, "Creou", "Criou", 0) /* linha 922 */
R(R_INICIO, "crear", "criar", 0) /* linha 923 */
R(R_INICIO, "creara", "criara", 0) /* linha 923 */
R(R_INICIO, "creará", "criará", 0) /* linha 924 */
R(R_INICIO, "crearam", "criaram", 0) /* linha 924 */
R(R_INICIO, "crearão", "criarão", 0) /* linha 925 */
R(R_INICIO, "creaste", "criaste", 0) /* linha 925 */
R(R_INICIO, "creado", "criado", 0) /* linha 926 */
R(R_INICIO, "creada", "criada", 0) /* linha 926 */
R(R_INICIO, "Creador", "Criador", 0) /* linha 927 */
R(R_INICIO, "creação", "criação", 0) /* linha 927 */
R(R_INICIO, "creatura", "criatura", 0) /* linha 928 */
R(R_INICIO, "creança", "criança", 0) /* linha 928 */
R(R_INICIO, "creancinha", "criancinha", 0) /* linha 929 */
R(R_INICIO, "veiu", "veio", 0) /* linha 931 */
R(R_INICIO, "Veiu", "Veio", 0) /* linha 931 */
R(R_INICIO, "quiz", "quis", 0) /* linha 932 */
R(R_INICIO, "poude", "pôde", 1) /* linha 933 */
R(R_INICIO, "podera", "pudera", 0) /* linha 934 */
R(R_INICIO, "poderam", "puderam", 0) /* linha 934 */
R(R_INICIO, "podesse", "pudesse", 0) /* linha 935 */
R(R_INICIO, "podessem", "pudessem", 0) /* linha 935 */
R(R_INICIO, "podeste", "pudeste", 0) /* linha 936 */
R(R_INICIO, "podestes", "pudestes", 0) /* linha 936 */
R(R_INICIO, "puz", "pus", 0) /* linha 937 */
R(R_INICIO, "Puz", "Pus", 0) /* linha 937 */
R(R_INICIO, "pozer", "puser", 0) /* linha 938 */
R(R_INICIO, "pozemos", "pusemos", 0) /* linha 938 */
R(R_INICIO, "pozesse", "pusesse", 0) /* linha 939 */
R(R_INICIO, "pozeste", "puseste", 0) /* linha 939 */
R(R_INICIO, "Pozeste", "Puseste", 0) /* linha 940 */
R(R_INICIO, "pozestes", "pusestes", 0) /* linha 940 */
R(R_TEXTO, " poz ", " pôs ", 0) /* linha 941 */
R(R_TEXTO, " poz,", " pôs,", 0) /* linha 941 */
R(R_TEXTO, " poz.", " pôs.", 0) /* linha 942 */
R(R_TEXTO, " poz;", " pôs;", 0) /* linha 942 */
R(R_INICIO, "Poz ", "Pôs ", 0) /* linha 943 */
R(R_INICIO, "pôz", "pôs", 0) /* linha 943 */
R(R_INICIO, "compoz", "compôs", 1) /* linha 944 */
R(R_INICIO, "depoz", "depôs", 1) /* linha 944 */
R(R_INICIO, "Depoz", "Depôs", 1) /* linha 945 */
R(R_INICIO, "dispoz", "dispôs", 1) /* linha 945 */
R(R_INICIO, "expoz", "expôs", 1) /* linha 946 */
R(R_INICIO, "impoz", "impôs", 1) /* linha 946 */
R(R_INICIO, "interpoz", "interpôs", 1) /* linha 947 */
R(R_INICIO, "oppoz", "opôs", 1) /* linha 947 */
R(R_INICIO, "propoz", "propôs", 1) /* linha 948 */
R(R_INICIO, "Propoz", "Propôs", 1) /* linha 948 */
R(R_INICIO, "propuz", "propus", 0) /* linha 949 */
R(R_INICIO, "Propuz", "Propus", 0) /* linha 949 */
R(R_INICIO, "sahi", "saí", 0) /* linha 951 */
R(R_INICIO, "Sahi", "Saí", 0) /* linha 951 */
R(R_INICIO, "sahia", "saía", 0) /* linha 952 */
R(R_INICIO, "sahis", "saís", 0) /* linha 952 */
R(R_INICIO, "cahi", "caí", 0) /* linha 953 */
R(R_INICIO, "Cahi", "Caí", 0) /* linha 953 */
R(R_INICIO, "cahia", "caía", 0) /* linha 954 */
R(R_INICIO, "trahi", "traí", 0) /* linha 955 */
R(R_INICIO, "trahir", "trair", 0) /* linha 955 */
R(R_INICIO, "distrahi", "distraí", 0) /* linha 956 */
R(R_INICIO, "trahe", "trai", 0) /* linha 957 */
R(R_INICIO, "bemaventurad", "bem-aventurad", 0) /* linha 959 */
R(R_INICIO, "Bemaventurad", "Bem-aventurad", 0) /* linha 960 */
R(R_INICIO, "bemaventuranç", "bem-aventuranç", 0) /* linha 961 */
R(R_INICIO, "Bemaventuranç", "Bem-aventuranç", 0) /* linha 962 */
R(R_INICIO, "Bem-Aventurad", "Bem-aventurad", 0) /* linha 963 */
R(R_INICIO, "Bem-Aventuranç", "Bem-aventuranç", 0) /* linha 964 */
/* Só a palavra "aza(s)"; antes estragava nomes: Azarias -> Asarias */
R(R_INTEIRA, "aza", "asa", 0) /* linha 967 */
R(R_INTEIRA, "azas", "asas", 0) /* linha 967 */
R(R_INTEIRA, "Azas", "Asas", 0) /* linha 968 */
R(R_INICIO, "vasia", "vazia", 0) /* linha 969 */
R(R_INICIO, "vasio", "vazio", 0) /* linha 969 */
R(R_INICIO, "abraza", "abrasa", 0) /* linha 970 */
R(R_INICIO, "abraze", "abrase", 0) /* linha 970 */
R(R_INICIO, "abrazou", "abrasou", 0) /* linha 971 */
R(R_INICIO, "arraza", "arrasa", 0) /* linha 971 */
R(R_INICIO, "atraz", "atrás", 1) /* linha 972 */
R(R_INICIO, "detraz", "detrás", 1) /* linha 972 */
R(R_INICIO, "apoz", "após", 1) /* linha 973 */
R(R_INICIO, "Apoz", "Após", 1) /* linha 973 */
R(R_INICIO, "defeza", "defesa", 0) /* linha 974 */
R(R_INICIO, "despeza", "despesa", 0) /* linha 974 */
R(R_INICIO, "princeza", "princesa", 0) /* linha 975 */
R(R_INICIO, "Princeza", "Princesa", 0) /* linha 975 */
R(R_INICIO, "turqueza", "turquesa", 0) /* linha 976 */
R(R_INICIO, "dezeseis", "dezesseis", 0) /* linha 977 */
R(R_INICIO, "dezesete", "dezessete", 0) /* linha 977 */
R(R_INICIO, "enteza", "entesa", 0) /* linha 978 */
R(R_INICIO, "pezo", "peso", 0) /* linha 978 */
R(R_INICIO, "Pezo", "Peso", 0) /* linha 979 */
R(R_INICIO, "peza", "pesa", 0) /* linha 979 */
R(R_INICIO, "apezar", "apesar", 0) /* linha 980 */
R(R_INICIO, "piza", "pisa", 0) /* linha 980 */
R(R_INICIO, "pizei", "pisei", 0) /* linha 981 */
R(R_INICIO, "pizem", "pisem", 0) /* linha 981 */
R(R_INICIO, "pizou", "pisou", 0) /* linha 982 */
R(R_INICIO, "pesquiza", "pesquisa", 0) /* linha 982 */
R(R_INICIO, "visinh", "vizinh", 0) /* linha 983 */
R(R_INICIO, "organisad", "organizad", 0) /* linha 984 */
R(R_INICIO, "atemoris", "atemoriz", 0) /* linha 985 */
R(R_INICIO, "aterroris", "aterroriz", 0) /* linha 986 */
R(R_INICIO, "cauteris", "cauteriz", 0) /* linha 987 */
R(R_INICIO, "encoleris", "encoleriz", 0) /* linha 988 */
R(R_INICIO, "penalis", "penaliz", 0) /* linha 989 */
R(R_INICIO, "realis", "realiz", 0) /* linha 990 */
R(R_INICIO, "paralys", "paralis", 0) /* linha 991 */
R(R_INICIO, "paralyt", "paralít", 1) /* linha 992 */
R(R_INICIO, "alcans", "alcanç", 1) /* linha 993 */
R(R_INICIO, "Alcans", "Alcanç", 1) /* linha 993 */
R(R_INICIO, "cança", "cansa", 0) /* linha 994 */
R(R_INICIO, "Cança", "Cansa", 0) /* linha 994 */
R(R_INICIO, "cance", "canse", 0) /* linha 995 */
R(R_INICIO, "cançou", "cansou", 0) /* linha 995 */
R(R_INICIO, "descanç", "descans", 0) /* linha 996 */
R(R_INICIO, "Descanç", "Descans", 0) /* linha 996 */
R(R_INICIO, "descanc", "descans", 0) /* linha 997 */
R(R_INICIO, "arremeç", "arremess", 0) /* linha 998 */
R(R_INICIO, "soceg", "sosseg", 0) /* linha 999 */
R(R_INICIO, "resuscit", "ressuscit", 0) /* linha 1000 */
R(R_INICIO, "Resuscit", "Ressuscit", 0) /* linha 1000 */
R(R_INICIO, "resurreição", "ressurreição", 0) /* linha 1001 */
R(R_INICIO, "sanguesuga", "sanguessuga", 0) /* linha 1002 */
R(R_INICIO, "outrosim", "outrossim", 0) /* linha 1003 */
R(R_INICIO, "Outrosim", "Outrossim", 0) /* linha 1003 */
R(R_INICIO, "adeante", "adiante", 0) /* linha 1005 */
R(R_INICIO, "deante", "diante", 0) /* linha 1005 */
R(R_INICIO, "edade", "idade", 0) /* linha 1006 */
R(R_INICIO, "edosos", "idosos", 0) /* linha 1006 */
R(R_INICIO, "egreja", "igreja", 0) /* linha 1007 */
R(R_INICIO, "egual", "igual", 0) /* linha 1008 */
R(R_INICIO, "Egual", "Igual", 0) /* linha 1008 */
R(R_INICIO, "eguais", "iguais", 0) /* linha 1009 */
R(R_INICIO, "desegua", "desigua", 0) /* linha 1009 */
R(R_INICIO, "emquanto", "enquanto", 0) /* linha 1010 */
R(R_INICIO, "Emquanto", "Enquanto", 0) /* linha 1010 */
R(R_INICIO, "comtanto", "contanto", 0) /* linha 1011 */
R(R_INICIO, "comtudo", "contudo", 0) /* linha 1012 */
R(R_INICIO, "Comtudo", "Contudo", 0) /* linha 1012 */
R(R_INICIO, "commigo", "comigo", 0) /* linha 1013 */
R(R_INICIO, "comnosco", "conosco", 0) /* linha 1013 */
R(R_INICIO, "comsigo", "consigo", 0) /* linha 1014 */
R(R_INICIO, "comtigo", "contigo", 0) /* linha 1014 */
R(R_INICIO, "Comtigo", "Contigo", 0) /* linha 1015 */
R(R_INICIO, "comvosco", "convosco", 0) /* linha 1015 */
R(R_INICIO, "bemdiz", "bendiz", 0) /* linha 1016 */
R(R_INICIO, "Bemdiz", "Bendiz", 0) /* linha 1016 */
R(R_INICIO, "bemdit", "bendit", 0) /* linha 1017 */
R(R_INICIO, "Bemdit", "Bendit", 0) /* linha 1017 */
R(R_INICIO, "bemdiss", "bendiss", 0) /* linha 1018 */
R(R_INICIO, "bemdig", "bendig", 0) /* linha 1018 */
R(R_INICIO, "bemdir", "bendir", 0) /* linha 1019 */
R(R_INICIO, "circum", "circun", 0) /* linha 1020 */
R(R_INICIO, "Circum", "Circun", 0) /* linha 1020 */
R(R_INICIO, "cincoenta", "cinquenta", 0) /* linha 1021 */
R(R_INICIO, "Cincoenta", "Cinquenta", 0) /* linha 1021 */
R(R_INICIO, "logar", "lugar", 0) /* linha 1022 */
R(R_INICIO, "herva", "erva", 0) /* linha 1022 */
R(R_INICIO, "Herva", "Erva", 0) /* linha 1023 */
R(R_INICIO, "similh", "semelh", 0) /* linha 1023 */
R(R_INICIO, "Similh", "Semelh", 0) /* linha 1024 */
R(R_INICIO, "quasi", "quase", 0) /* linha 1024 */
R(R_INICIO, "Quasi", "Quase", 0) /* linha 1025 */
R(R_INICIO, "peior", "pior", 0) /* linha 1025 */
R(R_INICIO, "engul", "engol", 0) /* linha 1026 */
R(R_INICIO, "Engul", "Engol", 0) /* linha 1026 */
R(R_INICIO, "cubriram", "cobriram", 0) /* linha 1027 */
R(R_INICIO, "cubriu", "cobriu", 0) /* linha 1027 */
R(R_INICIO, "inimisade", "inimizade", 0) /* linha 1028 */
R(R_INICIO, "magestade", "majestade", 0) /* linha 1029 */
R(R_INICIO, "Magestade", "Majestade", 0) /* linha 1029 */
R(R_INICIO, "mangedoura", "manjedoura", 0) /* linha 1030 */
R(R_INICIO, "engeita", "enjeita", 0) /* linha 1031 */
R(R_INICIO, "hereje", "herege", 0) /* linha 1031 */
R(R_INICIO, "lisonge", "lisonje", 0) /* linha 1032 */
R(R_INICIO, "bozin", "buzin", 0) /* linha 1032 */
/* Só "tribu(s)"; antes estragava tributo, tribuno, tribunal */
R(R_INTEIRA, "tribu", "tribo", 0) /* linha 1034 */
R(R_INTEIRA, "tribus", "tribos", 0) /* linha 1034 */
R(R_INICIO, "thesoiro", "tesouro", 0) /* linha 1035 */
R(R_INICIO, "taboado", "tabuado", 0) /* linha 1036 */
R(R_INICIO, "taboinha", "tabuinha", 0) /* linha 1036 */
R(R_INICIO, "taboa", "tábua", 1) /* linha 1037 */
R(R_INICIO, "taboas", "tábuas", 1) /* linha 1037 */
R(R_INICIO, "sobaco", "sovaco", 0) /* linha 1038 */
R(R_INICIO, "gloton", "gluton", 0) /* linha 1038 */
R(R_INICIO, "dextra", "destra", 0) /* linha 1039 */
R(R_INICIO, "Dextra", "Destra", 0) /* linha 1039 */
R(R_INICIO, "euro-aquilão", "euroaquilão", 0) /* linha 1040 */
R(R_INICIO, "comprehend", "compreend", 0) /* linha 1041 */
R(R_INICIO, "reprehens", "repreens", 0) /* linha 1042 */
R(R_INICIO, "reprehend", "repreend", 0) /* linha 1043 */
R(R_INICIO, "Reprehend", "Repreend", 0) /* linha 1043 */
R(R_INICIO, "surprehend", "surpreend", 0) /* linha 1044 */
R(R_INICIO, "Surprehend", "Surpreend", 0) /* linha 1044 */
R(R_INICIO, "emprehend", "empreend", 0) /* linha 1045 */
R(R_INICIO, "incomprehens", "incompreens", 0) /* linha 1046 */
R(R_INICIO, "ideia", "idea", 0) /* linha 1047 */
R(R_INICIO, "passeia", "passea", 0) /* linha 1047 */
R(R_INICIO, "receia", "recea", 0) /* linha 1048 */
R(R_INICIO, "rodeia", "rodea", 0) /* linha 1048 */
R(R_INICIO, "recreia", "recrea", 0) /* linha 1049 */
R(R_INICIO, "refreia", "refrea", 0) /* linha 1049 */
R(R_INICIO, "ceiar", "cear", 0) /* linha 1050 */
// 9. Acentuação moderna (remoção de acentos antigos e inclusão dos atuais)
R(R_INICIO, "crêem", "creem", 0) /* linha 1053 */
R(R_INICIO, "dêem", "deem", 0) /* linha 1053 */
R(R_INICIO, "Dêem", "Deem", 0) /* linha 1054 */
R(R_INICIO, "lêem", "leem", 0) /* linha 1054 */
R(R_INICIO, "vêem", "veem", 0) /* linha 1055 */
R(R_INICIO, "Vêem", "Veem", 0) /* linha 1055 */
R(R_INICIO, "vôo", "voo", 0) /* linha 1056 */
R(R_INICIO, "vôa", "voa", 0) /* linha 1056 */
R(R_INICIO, "vôem", "voem", 0) /* linha 1057 */
R(R_INICIO, "abençô", "abenço", 0) /* linha 1057 */
R(R_INICIO, "Abençô", "Abenço", 0) /* linha 1058 */
R(R_INICIO, "abençõe", "abençoe", 0) /* linha 1058 */
R(R_INICIO, "apregô", "aprego", 0) /* linha 1059 */
R(R_INICIO, "entôa", "entoa", 0) /* linha 1059 */
R(R_INICIO, "perdô", "perdo", 0) /* linha 1060 */
R(R_INICIO, "Perdô", "Perdo", 0) /* linha 1060 */
R(R_INICIO, "magõe", "magoe", 0) /* linha 1061 */
R(R_INICIO, "povôem", "povoem", 0) /* linha 1061 */
R(R_INICIO, "assembléa", "assembleia", 0) /* linha 1062 */
R(R_INICIO, "balêa", "baleia", 0) /* linha 1063 */
R(R_INICIO, "pavêa", "paveia", 0) /* linha 1063 */
R(R_INICIO, "têa", "teia", 0) /* linha 1064 */
R(R_INICIO, "côr", "cor", 0) /* linha 1064 */
R(R_INICIO, "cór", "cor", 0) /* linha 1065 */
R(R_INICIO, "dôr", "dor", 0) /* linha 1065 */
R(R_INICIO, "Dôr", "Dor", 0) /* linha 1066 */
R(R_INICIO, "flôr", "flor", 0) /* linha 1066 */
R(R_INICIO, "fôr", "for", 0) /* linha 1067 */
R(R_INICIO, "fóra", "fora", 0) /* linha 1067 */
R(R_INICIO, "Fóra", "Fora", 0) /* linha 1068 */
R(R_INICIO, "fôra", "fora", 0) /* linha 1068 */
R(R_INICIO, "Fôra", "Fora", 0) /* linha 1069 */
R(R_INICIO, "afóra", "afora", 0) /* linha 1069 */
R(R_INICIO, "Afóra", "Afora", 0) /* linha 1070 */
R(R_INICIO, "fórma", "forma", 0) /* linha 1070 */
R(R_INICIO, "fórmo", "formo", 0) /* linha 1071 */
R(R_INICIO, "sómente", "somente", 0) /* linha 1071 */
R(R_INICIO, "Sómente", "Somente", 0) /* linha 1072 */
R(R_INICIO, "sósinho", "sozinho", 0) /* linha 1072 */
R(R_INICIO, "páo", "pau", 0) /* linha 1073 */
R(R_INICIO, "páu", "pau", 0) /* linha 1073 */
R(R_INICIO, "máu", "mau", 0) /* linha 1074 */
R(R_INICIO, "váo", "vau", 0) /* linha 1074 */
R(R_INICIO, "náo", "nau", 0) /* linha 1075 */
R(R_INICIO, "náu", "nau", 0) /* linha 1075 */
R(R_INICIO, "degráu", "degrau", 0) /* linha 1076 */
R(R_INICIO, "póde", "pode", 0) /* linha 1076 */
R(R_INICIO, "pódes", "podes", 0) /* linha 1077 */
R(R_INICIO, "préga", "prega", 0) /* linha 1077 */
R(R_INICIO, "prég", "preg", 0) /* linha 1078 */
R(R_INICIO, "Prég", "Preg", 0) /* linha 1078 */
R(R_INICIO, "crêr", "crer", 0) /* linha 1079 */
R(R_INICIO, "lêr", "ler", 0) /* linha 1079 */
R(R_INICIO, "vêr", "ver", 0) /* linha 1080 */
R(R_INICIO, "crêde", "crede", 0) /* linha 1080 */
R(R_INICIO, "Crêde", "Crede", 0) /* linha 1081 */
R(R_INICIO, "crêdes", "credes", 0) /* linha 1081 */
R(R_INICIO, "Crêdes", "Credes", 0) /* linha 1082 */
R(R_INICIO, "crêmos", "cremos", 0) /* linha 1082 */
R(R_INICIO, "crêste", "creste", 0) /* linha 1083 */
R(R_INICIO, "lêde", "lede", 0) /* linha 1083 */
R(R_INICIO, "lêstes", "lestes", 0) /* linha 1084 */
R(R_INICIO, "vêde", "vede", 0) /* linha 1084 */
R(R_INICIO, "Vêde", "Vede", 0) /* linha 1085 */
R(R_INICIO, "vêdes", "vedes", 0) /* linha 1085 */
R(R_INICIO, "Vêdes", "Vedes", 0) /* linha 1086 */
R(R_INICIO, "dér", "der", 0) /* linha 1086 */
R(R_INICIO, "dés", "des", 0) /* linha 1087 */
R(R_INICIO, "désse", "desse", 0) /* linha 1087 */
R(R_INICIO, "déste", "deste", 0) /* linha 1088 */
R(R_INICIO, "Déste", "Deste", 0) /* linha 1088 */
R(R_INICIO, "démos", "demos", 0) /* linha 1089 */
R(R_INICIO, "podér", "poder", 0) /* linha 1089 */
R(R_INICIO, "podémos", "podemos", 0) /* linha 1090 */
R(R_INICIO, "têem", "têm", 0) /* linha 1090 */
R(R_INICIO, "teem", "têm", 1) /* linha 1091 */
R(R_INICIO, "Teem", "Têm", 1) /* linha 1091 */
R(R_INICIO, "detêem", "detêm", 0) /* linha 1092 */
R(R_INICIO, "deteem", "detêm", 1) /* linha 1092 */
R(R_INICIO, "mantêem", "mantêm", 0) /* linha 1093 */
R(R_INICIO, "manteem", "mantêm", 1) /* linha 1093 */
R(R_INICIO, "convêem", "convêm", 0) /* linha 1094 */
R(R_INICIO, "conveem", "convêm", 1) /* linha 1094 */
R(R_INICIO, "sobrevêem", "sobrevêm", 0) /* linha 1095 */
R(R_INICIO, "sobreveem", "sobrevêm", 1) /* linha 1095 */
R(R_INICIO, "sêde", "sede", 0) /* linha 1096 */
R(R_INICIO, "Sêde", "Sede", 0) /* linha 1096 */
R(R_INICIO, "convem", "convém", 1) /* linha 1097 */
R(R_INICIO, "Convem", "Convém", 1) /* linha 1097 */
R(R_INICIO, "detem", "detém", 1) /* linha 1098 */
R(R_INICIO, "mantem", "mantém", 1) /* linha 1098 */
R(R_INICIO, "sobrevem", "sobrevém", 1) /* linha 1099 */
R(R_INICIO, "véla", "vela", 0) /* linha 1100 */
R(R_INICIO, "vélas", "velas", 0) /* linha 1100 */
R(R_INICIO, "pátriarca", "patriarca", 0) /* linha 1101 */
R(R_INICIO, "fábricador", "fabricador", 0) /* linha 1102 */
R(R_TEXTO, "aos pães e às mães", "aos pais e às mães", 0) /* linha 1103 */
/* Só a palavra "ahi" (= aí); antes estragava nomes: Ahimaas -> Aímaas */
R(R_INTEIRA, "ahi", "aí", 0) /* linha 1105 */
R(R_INTEIRA, "Ahi", "Aí", 0) /* linha 1105 */
R(R_INICIO, "alli", "ali", 0) /* linha 1106 */
R(R_INICIO, "nú", "nu", 0) /* linha 1106 */
R(R_INICIO, "núa", "nua", 0) /* linha 1107 */
R(R_INICIO, "nús", "nus", 0) /* linha 1107 */
/* Só a palavra inteira; antes "homens" virava "homems" (1158 vezes) */
R(R_INTEIRA, "joven", "jovem", 0) /* linha 1109 */
R(R_INTEIRA, "homen", "homem", 0) /* linha 1109 */
R(R_INICIO, "algums", "alguns", 0) /* linha 1110 */
R(R_INTEIRA, "mez", "mês", 0) /* linha 1110 */
R(R_INICIO, "mezes", "meses", 0) /* linha 1111 */
R(R_INICIO, "tres", "três", 1) /* linha 1111 */
R(R_INICIO, "Tres", "Três", 1) /* linha 1112 */
R(R_INICIO, "paiz", "país", 1) /* linha 1112 */
R(R_INICIO, "paizes", "países", 1) /* linha 1113 */
R(R_INICIO, "Satanaz", "Satanás", 1) /* linha 1113 */
R(R_INICIO, "anneis", "anéis", 1) /* linha 1114 */
R(R_INICIO, "anzoes", "anzóis", 1) /* linha 1114 */
R(R_INICIO, "lençoes", "lençóis", 1) /* linha 1115 */
R(R_INICIO, "crueis", "cruéis", 1) /* linha 1115 */
R(R_INICIO, "infieis", "infiéis", 1) /* linha 1116 */
R(R_INICIO, "fieis", "fiéis", 1) /* linha 1116 */
R(R_INICIO, "chapeus", "chapéus", 1) /* linha 1117 */
R(R_INICIO, "arpéos", "arpéus", 0) /* linha 1117 */
R(R_INICIO, "parabens", "parabéns", 1) /* linha 1118 */
R(R_INICIO, "refens", "reféns", 1) /* linha 1118 */
R(R_INICIO, "armazens", "armazéns", 1) /* linha 1119 */
// Vocabulário com acentuação moderna
R(R_INICIO, "principio", "princípio", 1) /* linha 1122 */
R(R_INICIO, "Principio", "Princípio", 1) /* linha 1122 */
R(R_INICIO, "Espirito", "Espírito", 1) /* linha 1123 */
R(R_INICIO, "espirito", "espírito", 1) /* linha 1123 */
R(R_INICIO, "agua", "água", 1) /* linha 1124 */
R(R_INICIO, "Agua", "Água", 1) /* linha 1124 */
R(R_INICIO, "arvore", "árvore", 1) /* linha 1125 */
R(R_INICIO, "Arvore", "Árvore", 1) /* linha 1125 */
R(R_INICIO, "especie", "espécie", 1) /* linha 1126 */
R(R_INICIO, "reptil", "réptil", 1) /* linha 1126 */
R(R_INICIO, "reptis", "répteis", 1) /* linha 1127 */
R(R_INICIO, "femea", "fêmea", 1) /* linha 1127 */
R(R_INICIO, "gemeos", "gêmeos", 1) /* linha 1128 */
R(R_INICIO, "frutifera", "frutífera", 1) /* linha 1128 */
R(R_INICIO, "oleo", "óleo", 1) /* linha 1129 */
R(R_INICIO, "calix", "cálice", 1) /* linha 1129 */
R(R_INICIO, "gravida", "grávida", 1) /* linha 1130 */
R(R_INICIO, "gravido", "grávido", 1) /* linha 1130 */
R(R_INICIO, "unigenito", "unigênito", 1) /* linha 1131 */
R(R_INICIO, "Unigenito", "Unigênito", 1) /* linha 1131 */
R(R_INICIO, "folego", "fôlego", 1) /* linha 1132 */
R(R_INICIO, "Folego", "Fôlego", 1) /* linha 1132 */
R(R_INICIO, "bdelio", "bdélio", 1) /* linha 1133 */
R(R_INICIO, "carcere", "cárcere", 1) /* linha 1133 */
R(R_INICIO, "jubilo", "júbilo", 1) /* linha 1134 */
R(R_INICIO, "Jubilo", "Júbilo", 1) /* linha 1134 */
R(R_INICIO, "licito", "lícito", 1) /* linha 1135 */
R(R_INICIO, "ilicito", "ilícito", 1) /* linha 1135 */
R(R_INICIO, "unanime", "unânime", 1) /* linha 1136 */
R(R_INICIO, "Unanime", "Unânime", 1) /* linha 1136 */
R(R_INICIO, "incomod", "incômod", 1) /* linha 1137 */
R(R_INICIO, "ancora", "âncora", 1) /* linha 1137 */
R(R_INICIO, "imovel", "imóvel", 1) /* linha 1138 */
R(R_INICIO, "imoveis", "imóveis", 1) /* linha 1138 */
R(R_INICIO, "mutua", "mútua", 1) /* linha 1139 */
R(R_INICIO, "mutuo", "mútuo", 1) /* linha 1139 */
R(R_INICIO, "quadrupede", "quadrúpede", 1) /* linha 1140 */
R(R_INICIO, "imundicia", "imundícia", 1) /* linha 1140 */
R(R_INICIO, "malicia", "malícia", 1) /* linha 1141 */
R(R_INICIO, "Malicia", "Malícia", 1) /* linha 1141 */
R(R_INICIO, "seculo", "século", 1) /* linha 1142 */
R(R_INICIO, "Seculo", "Século", 1) /* linha 1142 */
R(R_INICIO, "incredul", "incrédul", 1) /* linha 1143 */
R(R_INICIO, "Incredul", "Incrédul", 1) /* linha 1143 */
R(R_INICIO, "proselit", "prosélit", 1) /* linha 1144 */
R(R_INICIO, "arabes", "árabes", 1) /* linha 1144 */
R(R_INICIO, "arido", "árido", 1) /* linha 1145 */
R(R_INICIO, "arida", "árida", 1) /* linha 1145 */
R(R_INICIO, "Amen", "Amém", 1) /* linha 1146 */
R(R_INICIO, "amen", "amém", 1) /* linha 1146 */
R(R_INICIO, "alguem", "alguém", 1) /* linha 1147 */
R(R_INICIO, "Alguem", "Alguém", 1) /* linha 1147 */
R(R_INICIO, "ninguem", "ninguém", 1) /* linha 1148 */
R(R_INICIO, "Ninguem", "Ninguém", 1) /* linha 1148 */
R(R_INICIO, "tambem", "também", 1) /* linha 1149 */
R(R_INICIO, "Tambem", "Também", 1) /* linha 1149 */
R(R_INICIO, "decima", "décima", 1) /* linha 1150 */
R(R_INICIO, "decimo", "décimo", 1) /* linha 1150 */
R(R_INICIO, "discipulo", "discípulo", 1) /* linha 1151 */
R(R_INICIO, "Discipulo", "Discípulo", 1) /* linha 1151 */
R(R_INICIO, "discipula", "discípula", 1) /* linha 1152 */
R(R_INICIO, "judeo", "judeu", 0) /* linha 1153 */
R(R_INICIO, "Judeo", "Judeu", 0) /* linha 1153 */
R(R_INICIO, "galileo", "galileu", 0) /* linha 1154 */
R(R_INICIO, "Galileo", "Galileu", 0) /* linha 1154 */
R(R_INICIO, "fariseo", "fariseu", 0) /* linha 1155 */
R(R_INICIO, "Fariseo", "Fariseu", 0) /* linha 1155 */
R(R_INICIO, "sadduceo", "saduceu", 0) /* linha 1156 */
R(R_INICIO, "gloria", "glória", 1) /* linha 1157 */
R(R_INICIO, "Gloria", "Glória", 1) /* linha 1157 */
R(R_INICIO, "misericordia", "misericórdia", 1) /* linha 1158 */
R(R_INICIO, "Misericordia", "Misericórdia", 1) /* linha 1158 */
R(R_INICIO, "juizo", "juízo", 1) /* linha 1159 */
R(R_INICIO, "paraiso", "paraíso", 1) /* linha 1159 */
R(R_INICIO, "Paraiso", "Paraíso", 1) /* linha 1160 */
R(R_INICIO, "saude", "saúde", 1) /* linha 1160 */
R(R_INICIO, "saudes", "saúdes", 1) /* linha 1161 */
R(R_INICIO, "saudo", "saúdo", 1) /* linha 1161 */
R(R_INICIO, "saudam", "saúdam", 1) /* linha 1162 */
R(R_INICIO, "Saudam", "Saúdam", 1) /* linha 1162 */
R(R_INICIO, "viuva", "viúva", 1) /* linha 1163 */
R(R_INICIO, "Viuva", "Viúva", 1) /* linha 1163 */
R(R_INICIO, "ruina", "ruína", 1) /* linha 1164 */
R(R_INICIO, "raizes", "raízes", 1) /* linha 1164 */
R(R_INICIO, "faisca", "faísca", 1) /* linha 1165 */
R(R_INICIO, "miuda", "miúda", 1) /* linha 1165 */
R(R_INICIO, "miudo", "miúdo", 1) /* linha 1166 */
R(R_INICIO, "moido", "moído", 1) /* linha 1166 */
R(R_INICIO, "roida", "roída", 1) /* linha 1167 */
R(R_INICIO, "saida", "saída", 1) /* linha 1167 */
R(R_INICIO, "saido", "saído", 1) /* linha 1168 */
R(R_INICIO, "caida", "caída", 1) /* linha 1168 */
R(R_INICIO, "caido", "caído", 1) /* linha 1169 */
R(R_INICIO, "destruida", "destruída", 1) /* linha 1169 */
R(R_INICIO, "destruido", "destruído", 1) /* linha 1170 */
R(R_INICIO, "possuida", "possuída", 1) /* linha 1170 */
R(R_INICIO, "possuido", "possuído", 1) /* linha 1171 */
R(R_INICIO, "restituida", "restituída", 1) /* linha 1171 */
R(R_INICIO, "restituido", "restituído", 1) /* linha 1172 */
R(R_INICIO, "instruida", "instruída", 1) /* linha 1172 */
R(R_INICIO, "instruido", "instruído", 1) /* linha 1173 */
R(R_INICIO, "construido", "construído", 1) /* linha 1173 */
R(R_INICIO, "instituido", "instituído", 1) /* linha 1174 */
R(R_INICIO, "constituido", "constituído", 1) /* linha 1174 */
R(R_INICIO, "concluido", "concluído", 1) /* linha 1175 */
R(R_INICIO, "excluido", "excluído", 1) /* linha 1175 */
R(R_INICIO, "diminuido", "diminuído", 1) /* linha 1176 */
R(R_INICIO, "attribue", "atribui", 0) /* linha 1176 */
R(R_INICIO, "constitue", "constitui", 0) /* linha 1177 */
R(R_INICIO, "diminue", "diminui", 0) /* linha 1177 */
R(R_INICIO, "exclue", "exclui", 0) /* linha 1178 */
R(R_INICIO, "instrue", "instrui", 0) /* linha 1178 */
R(R_INICIO, "possue", "possui", 0) /* linha 1179 */
R(R_INICIO, "restitue", "restitui", 0) /* linha 1179 */
R(R_INICIO, "retribue", "retribui", 0) /* linha 1180 */
R(R_INICIO, "destroe", "destrói", 1) /* linha 1180 */
R(R_INICIO, "Destroe", "Destrói", 1) /* linha 1181 */
R(R_INICIO, "obstroe", "obstrói", 1) /* linha 1181 */
R(R_INICIO, "orfão", "órfão", 1) /* linha 1182 */
R(R_INICIO, "orphão", "órfão", 0) /* linha 1182 */
R(R_INICIO, "Orphãos", "Órfãos", 0) /* linha 1183 */
R(R_INICIO, "orgão", "órgão", 1) /* linha 1183 */
R(R_INICIO, "apostolo", "apóstolo", 1) /* linha 1184 */
R(R_INICIO, "diacono", "diácono", 1) /* linha 1184 */
R(R_INICIO, "exercito", "exército", 1) /* linha 1185 */
R(R_INICIO, "Exercito", "Exército", 1) /* linha 1185 */
R(R_INICIO, "sacrificio", "sacrifício", 1) /* linha 1186 */
R(R_INICIO, "Sacrificio", "Sacrifício", 1) /* linha 1186 */
R(R_INICIO, "santuario", "santuário", 1) /* linha 1187 */
R(R_INICIO, "Santuario", "Santuário", 1) /* linha 1187 */
R(R_INICIO, "tabernaculo", "tabernáculo", 1) /* linha 1188 */
R(R_INICIO, "sinhedrio", "sinédrio", 0) /* linha 1189 */
R(R_INICIO, "adulterio", "adultério", 1) /* linha 1190 */
R(R_INICIO, "Adulterio", "Adultério", 1) /* linha 1190 */
R(R_INICIO, "homicidio", "homicídio", 1) /* linha 1191 */
R(R_INICIO, "fornicario", "fornicário", 1) /* linha 1191 */
R(R_INICIO, "idolo", "ídolo", 1) /* linha 1192 */
R(R_INICIO, "idolatras", "idólatras", 1) /* linha 1192 */
R(R_INICIO, "demonio", "demônio", 1) /* linha 1193 */
R(R_INICIO, "misterio", "mistério", 1) /* linha 1193 */
R(R_INICIO, "Misterio", "Mistério", 1) /* linha 1194 */
R(R_INICIO, "ministerio", "ministério", 1) /* linha 1194 */
R(R_INICIO, "epistola", "epístola", 1) /* linha 1195 */
R(R_INICIO, "cantico", "cântico", 1) /* linha 1195 */
R(R_INICIO, "Cantico", "Cântico", 1) /* linha 1196 */
R(R_INICIO, "proverbio", "provérbio", 1) /* linha 1196 */
R(R_INICIO, "Proverbio", "Provérbio", 1) /* linha 1197 */
R(R_INICIO, "sabio", "sábio", 1) /* linha 1197 */
R(R_INICIO, "nescio", "néscio", 1) /* linha 1198 */
R(R_INICIO, "Nescio", "Néscio", 1) /* linha 1198 */
R(R_INICIO, "impio", "ímpio", 1) /* linha 1199 */
R(R_INICIO, "iniquo", "iníquo", 1) /* linha 1199 */
R(R_INICIO, "principe", "príncipe", 1) /* linha 1200 */
R(R_INICIO, "Principe", "Príncipe", 1) /* linha 1200 */
R(R_INICIO, "palacio", "palácio", 1) /* linha 1201 */
R(R_INICIO, "edificio", "edifício", 1) /* linha 1201 */
R(R_INICIO, "atrio", "átrio", 1) /* linha 1202 */
R(R_INICIO, "vestibulo", "vestíbulo", 1) /* linha 1202 */
R(R_INICIO, "pinaculo", "pináculo", 1) /* linha 1203 */
R(R_INICIO, "portico", "pórtico", 1) /* linha 1203 */
R(R_INICIO, "marmore", "mármore", 1) /* linha 1204 */
R(R_INICIO, "fabrica", "fábrica", 1) /* linha 1204 */
R(R_INICIO, "lampada", "lâmpada", 1) /* linha 1205 */
R(R_INICIO, "perola", "pérola", 1) /* linha 1205 */
R(R_INICIO, "covados", "côvados", 1) /* linha 1206 */
R(R_INICIO, "tunica", "túnica", 1) /* linha 1206 */
R(R_INICIO, "sandalo", "sândalo", 1) /* linha 1207 */
R(R_INICIO, "ambar", "âmbar", 1) /* linha 1207 */
R(R_INICIO, "antimonio", "antimônio", 1) /* linha 1208 */
R(R_INICIO, "onix", "ônix", 1) /* linha 1208 */
R(R_INICIO, "Onix", "Ônix", 1) /* linha 1209 */
R(R_INICIO, "topazio", "topázio", 1) /* linha 1209 */
R(R_INICIO, "sardio", "sárdio", 1) /* linha 1210 */
R(R_INICIO, "sardonia", "sardônia", 1) /* linha 1210 */
R(R_INICIO, "sardonica", "sardônica", 1) /* linha 1211 */
R(R_INICIO, "crisolito", "crisólito", 1) /* linha 1211 */
R(R_INICIO, "crisopraso", "crisópraso", 1) /* linha 1212 */
R(R_INICIO, "Omega", "Ômega", 1) /* linha 1212 */
R(R_INICIO, "aguia", "águia", 1) /* linha 1213 */
R(R_INICIO, "passaro", "pássaro", 1) /* linha 1213 */
R(R_INICIO, "vibora", "víbora", 1) /* linha 1214 */
R(R_INICIO, "aspide", "áspide", 1) /* linha 1214 */
R(R_INICIO, "bufalo", "búfalo", 1) /* linha 1215 */
R(R_INICIO, "antilope", "antílope", 1) /* linha 1215 */
R(R_INICIO, "dromedario", "dromedário", 1) /* linha 1216 */
R(R_INICIO, "unicornio", "unicórnio", 1) /* linha 1216 */
R(R_INICIO, "lirio", "lírio", 1) /* linha 1217 */
R(R_INICIO, "aloes", "aloés", 1) /* linha 1217 */
R(R_INICIO, "alamo", "álamo", 1) /* linha 1218 */
R(R_INICIO, "amendoas", "amêndoas", 1) /* linha 1218 */
R(R_INICIO, "sicomoro", "sicômoro", 1) /* linha 1219 */
R(R_INICIO, "terebintho", "terebinto", 0) /* linha 1219 */
R(R_INICIO, "hipocrita", "hipócrita", 1) /* linha 1220 */
R(R_INICIO, "Hipocrita", "Hipócrita", 1) /* linha 1220 */
R(R_INICIO, "blasfemia", "blasfêmia", 1) /* linha 1221 */
R(R_INICIO, "perfidia", "perfídia", 1) /* linha 1221 */
R(R_INICIO, "perfido", "pérfido", 1) /* linha 1222 */
R(R_INICIO, "barbaro", "bárbaro", 1) /* linha 1222 */
R(R_INICIO, "bebado", "bêbado", 1) /* linha 1223 */
R(R_INICIO, "bebedo", "bêbedo", 1) /* linha 1223 */
R(R_INICIO, "ebrios", "ébrios", 1) /* linha 1224 */
R(R_INICIO, "lunatico", "lunático", 1) /* linha 1224 */
R(R_INICIO, "hidropico", "hidrópico", 1) /* linha 1225 */
R(R_INICIO, "pustula", "pústula", 1) /* linha 1225 */
R(R_INICIO, "cadaver", "cadáver", 1) /* linha 1226 */
R(R_INICIO, "feretro", "féretro", 1) /* linha 1226 */
R(R_INICIO, "relogio", "relógio", 1) /* linha 1227 */
R(R_INICIO, "salario", "salário", 1) /* linha 1227 */
R(R_INICIO, "denario", "denário", 1) /* linha 1228 */
R(R_INICIO, "drachma", "dracma", 0) /* linha 1228 */
R(R_INICIO, "didrachma", "didracma", 0) /* linha 1229 */
R(R_INICIO, "obolos", "óbolos", 1) /* linha 1229 */
R(R_INICIO, "státer", "estáter", 0) /* linha 1230 */
R(R_INICIO, "adversario", "adversário", 1) /* linha 1230 */
R(R_INICIO, "mercenario", "mercenário", 1) /* linha 1231 */
R(R_INICIO, "operario", "operário", 1) /* linha 1231 */
R(R_INICIO, "boticario", "boticário", 1) /* linha 1232 */
R(R_INICIO, "secretario", "secretário", 1) /* linha 1232 */
R(R_INICIO, "usurario", "usurário", 1) /* linha 1233 */
R(R_INICIO, "voluntario", "voluntário", 1) /* linha 1233 */
R(R_INICIO, "tributario", "tributário", 1) /* linha 1234 */
R(R_INICIO, "hereditari", "hereditári", 1) /* linha 1234 */
R(R_INICIO, "necessari", "necessári", 1) /* linha 1235 */
R(R_INICIO, "Necessari", "Necessári", 1) /* linha 1235 */
R(R_INICIO, "ordinaria", "ordinária", 1) /* linha 1236 */
R(R_INICIO, "extraordinaria", "extraordinária", 1) /* linha 1236 */
R(R_INICIO, "transitori", "transitóri", 1) /* linha 1237 */
R(R_INICIO, "momentanea", "momentânea", 1) /* linha 1237 */
R(R_INICIO, "corporea", "corpórea", 1) /* linha 1238 */
R(R_INICIO, "idoneo", "idôneo", 1) /* linha 1238 */
R(R_INICIO, "aspero", "áspero", 1) /* linha 1239 */
R(R_INICIO, "candido", "cândido", 1) /* linha 1239 */
R(R_INICIO, "timido", "tímido", 1) /* linha 1240 */
R(R_INICIO, "sordido", "sórdido", 1) /* linha 1240 */
R(R_INICIO, "sobrio", "sóbrio", 1) /* linha 1241 */
R(R_INICIO, "proprio", "próprio", 1) /* linha 1241 */
R(R_INICIO, "propria", "própria", 1) /* linha 1242 */
R(R_INICIO, "proximo", "próximo", 1) /* linha 1242 */
R(R_INICIO, "proxima", "próxima", 1) /* linha 1243 */
R(R_INICIO, "insipido", "insípido", 1) /* linha 1243 */
R(R_INICIO, "ultimo", "último", 1) /* linha 1244 */
R(R_INICIO, "minimo", "mínimo", 1) /* linha 1244 */
R(R_INICIO, "minimas", "mínimas", 1) /* linha 1245 */
R(R_INICIO, "intimo", "íntimo", 1) /* linha 1245 */
R(R_INICIO, "continuo", "contínuo", 1) /* linha 1246 */
R(R_INICIO, "perpetuo", "perpétuo", 1) /* linha 1246 */
R(R_INICIO, "contrario", "contrário", 1) /* linha 1247 */
R(R_INICIO, "vario", "vário", 1) /* linha 1247 */
R(R_INICIO, "solitari", "solitári", 1) /* linha 1248 */
R(R_INICIO, "maritima", "marítima", 1) /* linha 1248 */
R(R_INICIO, "domestico", "doméstico", 1) /* linha 1249 */
R(R_INICIO, "rustico", "rústico", 1) /* linha 1249 */
R(R_INICIO, "magico", "mágico", 1) /* linha 1250 */
R(R_INICIO, "magnifico", "magnífico", 1) /* linha 1250 */
R(R_INICIO, "pessimo", "péssimo", 1) /* linha 1251 */
R(R_INICIO, "atonito", "atônito", 1) /* linha 1251 */
R(R_INICIO, "longanimo", "longânimo", 1) /* linha 1252 */
R(R_INICIO, "solicito", "solícito", 1) /* linha 1252 */
R(R_INICIO, "temerario", "temerário", 1) /* linha 1253 */
R(R_INICIO, "propinquo", "propínquo", 1) /* linha 1253 */
R(R_INICIO, "setima", "sétima", 1) /* linha 1254 */
R(R_INICIO, "setimo", "sétimo", 1) /* linha 1254 */
R(R_INICIO, "undecim", "undécim", 1) /* linha 1255 */
R(R_INICIO, "duodecim", "duodécim", 1) /* linha 1255 */
R(R_INICIO, "vigesim", "vigésim", 1) /* linha 1256 */
R(R_INICIO, "trigesim", "trigésim", 1) /* linha 1256 */
R(R_INICIO, "quadragesim", "quadragésim", 1) /* linha 1257 */
R(R_INICIO, "quinquagesim", "quinquagésim", 1) /* linha 1257 */
R(R_INICIO, "lingua", "língua", 1) /* linha 1258 */
R(R_INICIO, "mingua", "míngua", 1) /* linha 1258 */
R(R_INICIO, "argúe", "argui", 0) /* linha 1259 */
R(R_INICIO, "redargue", "redargui", 0) /* linha 1259 */
R(R_INICIO, "beneficio", "benefício", 1) /* linha 1260 */
R(R_INICIO, "maleficio", "malefício", 1) /* linha 1260 */
R(R_INICIO, "exercicio", "exercício", 1) /* linha 1261 */
R(R_INICIO, "officio", "ofício", 1) /* linha 1261 */
R(R_INICIO, "desperdicio", "desperdício", 1) /* linha 1262 */
R(R_INICIO, "precipicio", "precipício", 1) /* linha 1262 */
R(R_INICIO, "prejuizo", "prejuízo", 1) /* linha 1263 */
R(R_INICIO, "prepucio", "prepúcio", 1) /* linha 1263 */
R(R_INICIO, "negocio", "negócio", 1) /* linha 1264 */
R(R_INICIO, "sacerdocio", "sacerdócio", 1) /* linha 1264 */
R(R_INICIO, "sacrilegio", "sacrilégio", 1) /* linha 1265 */
R(R_INICIO, "imperio", "império", 1) /* linha 1265 */
R(R_INICIO, "dominio", "domínio", 1) /* linha 1266 */
R(R_INICIO, "testiculo", "testículo", 1) /* linha 1266 */
R(R_INICIO, "musculo", "músculo", 1) /* linha 1267 */
R(R_INICIO, "musico", "músico", 1) /* linha 1267 */
R(R_INICIO, "cimbalo", "címbalo", 1) /* linha 1268 */
R(R_INICIO, "salterio", "saltério", 1) /* linha 1268 */
R(R_INICIO, "pulpito", "púlpito", 1) /* linha 1269 */
R(R_INICIO, "auditorio", "auditório", 1) /* linha 1269 */
R(R_INICIO, "concilio", "concílio", 1) /* linha 1270 */
R(R_INICIO, "pretorio", "pretório", 1) /* linha 1270 */
R(R_INICIO, "territorio", "território", 1) /* linha 1271 */
R(R_INICIO, "provincia", "província", 1) /* linha 1271 */
R(R_INICIO, "planicie", "planície", 1) /* linha 1272 */
R(R_INICIO, "superficie", "superfície", 1) /* linha 1272 */
R(R_INICIO, "vespera", "véspera", 1) /* linha 1273 */
R(R_INICIO, "vigilia", "vigília", 1) /* linha 1273 */
R(R_INICIO, "memoria", "memória", 1) /* linha 1274 */
R(R_INICIO, "familia", "família", 1) /* linha 1274 */
R(R_INICIO, "patria", "pátria", 1) /* linha 1275 */
R(R_INICIO, "materia", "matéria", 1) /* linha 1275 */
R(R_INICIO, "miseria", "miséria", 1) /* linha 1276 */
R(R_INICIO, "lagrima", "lágrima", 1) /* linha 1276 */
R(R_INICIO, "reliquia", "relíquia", 1) /* linha 1277 */
R(R_INICIO, "remedio", "remédio", 1) /* linha 1277 */
R(R_INICIO, "refrigerio", "refrigério", 1) /* linha 1278 */
R(R_INICIO, "oprobrio", "opróbrio", 1) /* linha 1278 */
R(R_INICIO, "vituperio", "vitupério", 1) /* linha 1279 */
R(R_INICIO, "escarnio", "escárnio", 1) /* linha 1279 */
R(R_INICIO, "escarneo", "escárnio", 1) /* linha 1280 */
R(R_INICIO, "tedio", "tédio", 1) /* linha 1280 */
R(R_INICIO, "odio", "ódio", 1) /* linha 1281 */
R(R_INICIO, "incendio", "incêndio", 1) /* linha 1281 */
R(R_INICIO, "naufragio", "naufrágio", 1) /* linha 1282 */
R(R_INICIO, "prodigio", "prodígio", 1) /* linha 1282 */
R(R_INICIO, "designio", "desígnio", 1) /* linha 1283 */
R(R_INICIO, "equilibrio", "equilíbrio", 1) /* linha 1283 */
R(R_INICIO, "comercio", "comércio", 1) /* linha 1284 */
R(R_INICIO, "comodo", "cômodo", 1) /* linha 1284 */
R(R_INICIO, "colera", "cólera", 1) /* linha 1285 */
R(R_INICIO, "colerico", "colérico", 1) /* linha 1285 */
R(R_INICIO, "angulo", "ângulo", 1) /* linha 1286 */
R(R_INICIO, "animo", "ânimo", 1) /* linha 1286 */
R(R_INICIO, "camara", "câmara", 1) /* linha 1287 */
R(R_INICIO, "cantaro", "cântaro", 1) /* linha 1287 */
R(R_INICIO, "genero", "gênero", 1) /* linha 1288 */
R(R_INICIO, "craneo", "crânio", 1) /* linha 1288 */
R(R_INICIO, "crepusculo", "crepúsculo", 1) /* linha 1289 */
R(R_INICIO, "espetaculo", "espetáculo", 1) /* linha 1289 */
R(R_INICIO, "estadio", "estádio", 1) /* linha 1290 */
R(R_INICIO, "esteril", "estéril", 1) /* linha 1290 */
R(R_INICIO, "facil", "fácil", 1) /* linha 1291 */
R(R_INICIO, "fertil", "fértil", 1) /* linha 1291 */
R(R_INICIO, "fragil", "frágil", 1) /* linha 1292 */
R(R_INICIO, "habil", "hábil", 1) /* linha 1292 */
R(R_INICIO, "util", "útil", 1) /* linha 1293 */
R(R_INICIO, "Util", "Útil", 1) /* linha 1293 */
R(R_INICIO, "debil", "débil", 1) /* linha 1294 */
R(R_INICIO, "nivel", "nível", 1) /* linha 1294 */
R(R_INICIO, "vacuo", "vácuo", 1) /* linha 1295 */
R(R_INICIO, "residuo", "resíduo", 1) /* linha 1295 */
R(R_INICIO, "vomito", "vômito", 1) /* linha 1296 */
R(R_INICIO, "nadegas", "nádegas", 1) /* linha 1296 */
R(R_INICIO, "palpebras", "pálpebras", 1) /* linha 1297 */
R(R_INICIO, "pateo", "pátio", 1) /* linha 1297 */
R(R_INICIO, "alviçaras", "alvíssaras", 0) /* linha 1298 */
R(R_INICIO, "arruido", "arruído", 1) /* linha 1298 */
R(R_INICIO, "arroido", "arruído", 1) /* linha 1299 */
R(R_INICIO, "vaevens", "vaivéns", 1) /* linha 1299 */
R(R_INICIO, "vergonteas", "vergônteas", 1) /* linha 1300 */
R(R_INICIO, "violencia", "violência", 1) /* linha 1300 */
R(R_INICIO, "Violencia", "Violência", 1) /* linha 1301 */
R(R_INICIO, "modestia", "modéstia", 1) /* linha 1301 */
R(R_INICIO, "molestia", "moléstia", 1) /* linha 1302 */
R(R_INICIO, "estulticia", "estultícia", 1) /* linha 1302 */
R(R_INICIO, "infamia", "infâmia", 1) /* linha 1303 */
R(R_INICIO, "concordia", "concórdia", 1) /* linha 1303 */
R(R_INICIO, "primicia", "primícia", 1) /* linha 1304 */
R(R_INICIO, "primogenit", "primogênit", 1) /* linha 1304 */
R(R_INICIO, "proposito", "propósito", 1) /* linha 1305 */
R(R_INICIO, "beneplacito", "beneplácito", 1) /* linha 1305 */
R(R_INICIO, "emprestimo", "empréstimo", 1) /* linha 1306 */
R(R_INICIO, "artifice", "artífice", 1) /* linha 1306 */
R(R_INICIO, "astrologo", "astrólogo", 1) /* linha 1307 */
R(R_INICIO, "dormitorio", "dormitório", 1) /* linha 1307 */
R(R_INICIO, "incensario", "incensário", 1) /* linha 1308 */
R(R_INICIO, "luminaria", "luminária", 1) /* linha 1308 */
R(R_INICIO, "propiciatorio", "propiciatório", 1) /* linha 1309 */
R(R_INICIO, "decrepito", "decrépito", 1) /* linha 1310 */
R(R_INICIO, "efigie", "efígie", 1) /* linha 1310 */
R(R_INICIO, "emissario", "emissário", 1) /* linha 1311 */
R(R_INICIO, "lapidario", "lapidário", 1) /* linha 1311 */
R(R_INICIO, "natalicio", "natalício", 1) /* linha 1312 */
R(R_INICIO, "neofito", "neófito", 1) /* linha 1312 */
R(R_INICIO, "reprobo", "réprobo", 1) /* linha 1313 */
R(R_INICIO, "satiro", "sátiro", 1) /* linha 1313 */
R(R_INICIO, "serodia", "serôdia", 1) /* linha 1314 */
R(R_INICIO, "similes", "símiles", 1) /* linha 1314 */
R(R_INICIO, "porfiro", "pórfiro", 1) /* linha 1315 */
R(R_INICIO, "setestrelo", "Sete-Estrelo", 0) /* linha 1315 */
R(R_INICIO, "Setestrelo", "Sete-Estrelo", 0) /* linha 1316 */
R(R_INICIO, "Todo-poderoso", "Todo-Poderoso", 0) /* linha 1317 */
R(R_INICIO, "refugio", "refúgio", 1) /* linha 1318 */
R(R_INICIO, "angustia", "angústia", 1) /* linha 1319 */
R(R_INICIO, "angustias", "angústias", 1) /* linha 1320 */
R(R_TEXTO, "-ha ", "-á ", 0) /* linha 1321 */
R(R_TEXTO, "-ha.", "-á.", 0) /* linha 1321 */
R(R_TEXTO, "-ha,", "-á,", 0) /* linha 1322 */
// 10. Padronização de nomes próprios bíblicos e geográficos (pt-BR)
R(R_INICIO, "Abrahão", "Abraão", 0) /* linha 1325 */
R(R_INICIO, "Sarah", "Sara", 0) /* linha 1326 */
R(R_INICIO, "David", "Davi", 0) /* linha 1327 */
R(R_INICIO, "Jacob", "Jacó", 1) /* linha 1328 */
R(R_INICIO, "Isaac", "Isaque", 0) /* linha 1329 */
R(R_INICIO, "Rachab", "Raabe", 0) /* linha 1330 */
R(R_INICIO, "Rahab", "Raabe", 0) /* linha 1331 */
R(R_INICIO, "Rut", "Rute", 0) /* linha 1332 */
R(R_INICIO, "Obed", "Obede", 0) /* linha 1333 */
R(R_INICIO, "Josafat", "Josafá", 1) /* linha 1334 */
R(R_INICIO, "Achaz", "Acaz", 0) /* linha 1335 */
R(R_INICIO, "Amon", "Amom", 0) /* linha 1336 */
R(R_INICIO, "Jechonias", "Jeconias", 0) /* linha 1337 */
R(R_INICIO, "Eliakim", "Eliaquim", 0) /* linha 1338 */
R(R_INICIO, "Sadoc", "Sadoque", 0) /* linha 1339 */
R(R_INICIO, "Achim", "Aquim", 0) /* linha 1340 */
R(R_INICIO, "Eliud", "Eliúde", 1) /* linha 1341 */
R(R_INICIO, "Matan", "Matã", 1) /* linha 1342 */
R(R_INICIO, "Emmanuel", "Emanuel", 0) /* linha 1343 */
R(R_INICIO, "EMMANUEL", "EMANUEL", 0) /* linha 1344 */
R(R_INICIO, "Gideon", "Gideão", 1) /* linha 1345 */
R(R_INICIO, "Jefte", "Jefté", 1) /* linha 1346 */
R(R_INICIO, "Zacharias", "Zacarias", 0) /* linha 1347 */
R(R_INICIO, "Poncio", "Pôncio", 1) /* linha 1348 */
R(R_INICIO, "Iturea", "Itureia", 0) /* linha 1349 */
R(R_INICIO, "Abilinia", "Abilene", 0) /* linha 1350 */
R(R_INICIO, "Eden", "Éden", 1) /* linha 1351 */
R(R_INICIO, "Aristarcho", "Aristarco", 0) /* linha 1352 */
R(R_INICIO, "macedonio", "macedônio", 1) /* linha 1353 */
R(R_INICIO, "Fenix", "Fênix", 1) /* linha 1354 */
R(R_INICIO, "Adriatico", "Adriático", 1) /* linha 1355 */
R(R_INICIO, "Moises", "Moisés", 1) /* linha 1356 */
R(R_INICIO, "Jehovah", "Jeová", 0) /* linha 1357 */
R(R_INICIO, "JEHOVAH", "JEOVÁ", 1) /* linha 1357 */
R(R_INICIO, "Egipto", "Egito", 0) /* linha 1358 */
R(R_INICIO, "egipci", "egípci", 1) /* linha 1359 */
R(R_INICIO, "Egipci", "Egípci", 1) /* linha 1359 */
R(R_INICIO, "Jerusalem", "Jerusalém", 1) /* linha 1360 */
R(R_INICIO, "Betlehem", "Belém", 0) /* linha 1361 */
R(R_INICIO, "Bethlehem", "Belém", 0) /* linha 1361 */
R(R_INICIO, "Nazaret", "Nazaré", 1) /* linha 1362 */
R(R_INICIO, "Galilea", "Galileia", 0) /* linha 1363 */
R(R_INICIO, "Galiléa", "Galileia", 0) /* linha 1363 */
R(R_INICIO, "Judea", "Judeia", 0) /* linha 1364 */
R(R_INICIO, "Judéa", "Judeia", 0) /* linha 1364 */
R(R_INICIO, "Laodicea", "Laodiceia", 0) /* linha 1365 */
R(R_INICIO, "Laodicéa", "Laodiceia", 0) /* linha 1365 */
R(R_INICIO, "Cesarea", "Cesareia", 0) /* linha 1366 */
R(R_INICIO, "Berea", "Bereia", 0) /* linha 1366 */
R(R_INICIO, "Betania", "Betânia", 1) /* linha 1367 */
R(R_INICIO, "Getsemane", "Getsêmani", 1) /* linha 1368 */
R(R_INICIO, "Golgota", "Gólgota", 1) /* linha 1368 */
R(R_INICIO, "Timoteo", "Timóteo", 1) /* linha 1369 */
R(R_INICIO, "Bartolomeo", "Bartolomeu", 0) /* linha 1370 */
R(R_INICIO, "Teofilo", "Teófilo", 1) /* linha 1371 */
R(R_INICIO, "Enoch", "Enoque", 0) /* linha 1372 */
R(R_INICIO, "Henoch", "Enoque", 0) /* linha 1373 */
R(R_INICIO, "Lamech", "Lameque", 0) /* linha 1374 */
R(R_INICIO, "Melquisedec", "Melquisedeque", 0) /* linha 1375 */
R(R_INICIO, "Abimelech", "Abimeleque", 0) /* linha 1376 */
R(R_INICIO, "Elimelech", "Elimeleque", 0) /* linha 1377 */
R(R_INICIO, "Baruch", "Baruque", 0) /* linha 1378 */
R(R_INICIO, "Eliseo", "Eliseu", 0) /* linha 1379 */
R(R_INICIO, "Zaqueo", "Zaqueu", 0) /* linha 1380 */
R(R_INICIO, "Mardoqueo", "Mardoqueu", 0) /* linha 1381 */
R(R_INICIO, "Isaias", "Isaías", 1) /* linha 1382 */
R(R_INICIO, "Oseas", "Oseias", 0) /* linha 1383 */
R(R_INICIO, "Miqueas", "Miqueias", 0) /* linha 1384 */
R(R_INICIO, "Ageo", "Ageu", 0) /* linha 1385 */
R(R_INICIO, "corintios", "coríntios", 1) /* linha 1386 */
R(R_INICIO, "Tessalonica", "Tessalônica", 1) /* linha 1387 */
R(R_INICIO, "Iconio", "Icônio", 1) /* linha 1388 */
R(R_INICIO, "Tiquico", "Tíquico", 1) /* linha 1389 */
R(R_INICIO, "Onesiforo", "Onesíforo", 1) /* linha 1390 */
R(R_INICIO, "Diotrefes", "Diótrefes", 1) /* linha 1391 */
R(R_INICIO, "Demetrio", "Demétrio", 1) /* linha 1392 */
R(R_INICIO, "Cornelio", "Cornélio", 1) /* linha 1393 */
R(R_INICIO, "Sergio", "Sérgio", 1) /* linha 1394 */
R(R_INICIO, "Claudio", "Cláudio", 1) /* linha 1395 */
R(R_INICIO, "Julio", "Júlio", 1) /* linha 1396 */
R(R_INICIO, "Felix", "Félix", 1) /* linha 1397 */
R(R_INICIO, "Tiberio", "Tibério", 1) /* linha 1398 */
R(R_INICIO, "Cesar", "César", 1) /* linha 1399 */
R(R_INICIO, "Fenicia", "Fenícia", 1) /* linha 1400 */
R(R_INICIO, "Frigia", "Frígia", 1) /* linha 1401 */
R(R_INICIO, "Panfilia", "Panfília", 1) /* linha 1402 */
R(R_INICIO, "Licia", "Lícia", 1) /* linha 1403 */
R(R_INICIO, "Licaonia", "Licaônia", 1) /* linha 1404 */
R(R_INICIO, "Misia", "Mísia", 1) /* linha 1405 */
R(R_INICIO, "Bitinia", "Bitínia", 1) /* linha 1406 */
R(R_INICIO, "Capadocia", "Capadócia", 1) /* linha 1407 */
R(R_INICIO, "Cilicia", "Cilícia", 1) /* linha 1408 */
R(R_INICIO, "Galacia", "Galácia", 1) /* linha 1409 */
R(R_INICIO, "Macedonia", "Macedônia", 1) /* linha 1410 */
R(R_INICIO, "Ilirico", "Ilírico", 1) /* linha 1411 */
R(R_INICIO, "Italia", "Itália", 1) /* linha 1412 */
R(R_INICIO, "ciprio", "cíprio", 1) /* linha 1413 */
R(R_INICIO, "Libia", "Líbia", 1) /* linha 1414 */
R(R_INICIO, "Etiopia", "Etiópia", 1) /* linha 1415 */
R(R_INICIO, "etiope", "etíope", 1) /* linha 1415 */
R(R_INICIO, "Mesopotamia", "Mesopotâmia", 1) /* linha 1416 */
R(R_INICIO, "Assiria", "Assíria", 1) /* linha 1417 */
R(R_INICIO, "assirios", "assírios", 1) /* linha 1417 */
R(R_INICIO, "Babilonia", "Babilônia", 1) /* linha 1418 */
R(R_INICIO, "babilonios", "babilônios", 1) /* linha 1418 */
R(R_INICIO, "Persia", "Pérsia", 1) /* linha 1419 */
R(R_INICIO, "Grecia", "Grécia", 1) /* linha 1420 */
R(R_INICIO, "Siquem", "Siquém", 1) /* linha 1421 */
R(R_INICIO, "sidonios", "sidônios", 1) /* linha 1422 */
R(R_INICIO, "tirios", "tírios", 1) /* linha 1422 */
R(R_INICIO, "Libano", "Líbano", 1) /* linha 1423 */
R(R_INICIO, "Siao", "Sião", 1) /* linha 1424 */
R(R_INICIO, "Moriah", "Moriá", 0) /* linha 1425 */
R(R_INICIO, "hebreo", "hebreu", 0) /* linha 1426 */
R(R_INICIO, "Hebreo", "Hebreu", 0) /* linha 1426 */
R(R_INICIO, "caldeo", "caldeu", 0) /* linha 1427 */
R(R_INICIO, "Caldeo", "Caldeu", 0) /* linha 1427 */
R(R_INICIO, "cananeo", "cananeu", 0) /* linha 1428 */
R(R_INICIO, "Cananeo", "Cananeu", 0) /* linha 1428 */
R(R_INICIO, "idumeo", "idumeu", 0) /* linha 1429 */
R(R_INICIO, "Idumeo", "Idumeu", 0) /* linha 1429 */
R(R_INICIO, "amoreo", "amorreu", 0) /* linha 1430 */
R(R_INICIO, "Amoreo", "Amorreu", 0) /* linha 1430 */
R(R_INICIO, "heteo", "heteu", 0) /* linha 1431 */
R(R_INICIO, "heveo", "heveu", 0) /* linha 1431 */
R(R_INICIO, "Heveo", "Heveu", 0) /* linha 1432 */
R(R_INICIO, "jebuseo", "jebuseu", 0) /* linha 1432 */
R(R_INICIO, "Jebuseo", "Jebuseu", 0) /* linha 1433 */
R(R_INICIO, "pereseo", "perizeu", 0) /* linha 1433 */
R(R_INICIO, "fereseo", "perizeu", 0) /* linha 1434 */
R(R_INICIO, "Fereseus", "Perizeus", 0) /* linha 1434 */
R(R_INICIO, "filisteo", "filisteu", 0) /* linha 1435 */
R(R_INICIO, "sabeo", "sabeu", 0) /* linha 1435 */
R(R_INICIO, "sidoneo", "sidônio", 1) /* linha 1436 */
// 11. Adaptação lexical e sintática para o leitor do Brasil (PT-BR)
R(R_INTEIRA, "rapariga", "moça", 0) /* linha 1439 */
R(R_INTEIRA, "Rapariga", "Moça", 0) /* linha 1440 */
R(R_INTEIRA, "raparigas", "moças", 0) /* linha 1441 */
R(R_INTEIRA, "Raparigas", "Moças", 0) /* linha 1442 */
R(R_INTEIRA, "rapariguinha", "mocinha", 0) /* linha 1443 */
R(R_INTEIRA, "Rapariguinha", "Mocinha", 0) /* linha 1444 */
R(R_INTEIRA, "mancebo", "jovem", 0) /* linha 1446 */
R(R_INTEIRA, "Mancebo", "Jovem", 0) /* linha 1447 */
R(R_INTEIRA, "mancebos", "jovens", 0) /* linha 1448 */
R(R_INTEIRA, "Mancebos", "Jovens", 0) /* linha 1449 */
R(R_INTEIRA, "cachopa", "menina", 0) /* linha 1451 */
R(R_INTEIRA, "Cachopa", "Menina", 0) /* linha 1452 */
R(R_INTEIRA, "cachopas", "meninas", 0) /* linha 1453 */
R(R_INTEIRA, "Cachopas", "Meninas", 0) /* linha 1454 */
R(R_INTEIRA, "cachopo", "menino", 0) /* linha 1455 */
R(R_INTEIRA, "Cachopo", "Menino", 0) /* linha 1456 */
R(R_INTEIRA, "cachopos", "meninos", 0) /* linha 1457 */
R(R_INTEIRA, "Cachopos", "Meninos", 0) /* linha 1458 */
R(R_INTEIRA, "varões", "homens", 0) /* linha 1460 */
R(R_INTEIRA, "Varões", "Homens", 0) /* linha 1461 */
R(R_INTEIRA, "ósculo", "beijo", 0) /* linha 1463 */
R(R_INTEIRA, "Ósculo", "Beijo", 0) /* linha 1464 */
R(R_INTEIRA, "ósculos", "beijos", 0) /* linha 1465 */
R(R_INTEIRA, "Ósculos", "Beijos", 0) /* linha 1466 */
R(R_INTEIRA, "lume", "luz", 0) /* linha 1468 */
R(R_INTEIRA, "Lume", "Luz", 0) /* linha 1469 */
R(R_INTEIRA, "púcaro", "jarro", 0) /* linha 1471 */
R(R_INTEIRA, "Púcaro", "Jarro", 0) /* linha 1472 */
R(R_INTEIRA, "púcaros", "jarros", 0) /* linha 1473 */
R(R_INTEIRA, "púcara", "jarra", 0) /* linha 1474 */
R(R_INTEIRA, "Púcara", "Jarra", 0) /* linha 1475 */
R(R_INTEIRA, "púcaras", "jarras", 0) /* linha 1476 */
R(R_INTEIRA, "azorrague", "chicote", 0) /* linha 1478 */
R(R_INTEIRA, "Azorrague", "Chicote", 0) /* linha 1479 */
R(R_INTEIRA, "azorragues", "chicotes", 0) /* linha 1480 */
R(R_INTEIRA, "alfaias", "utensílios", 0) /* linha 1481 */
R(R_INTEIRA, "algibeira", "bolso", 0) /* linha 1482 */
R(R_INTEIRA, "algibeiras", "bolsos", 0) /* linha 1483 */
R(R_INTEIRA, "postigo", "janela", 0) /* linha 1484 */
R(R_INTEIRA, "regato", "riacho", 0) /* linha 1485 */
R(R_INTEIRA, "regatos", "riachos", 0) /* linha 1486 */
R(R_INTEIRA, "verdugo", "carrasco", 0) /* linha 1487 */
R(R_INTEIRA, "verdugos", "carrascos", 0) /* linha 1488 */
R(R_INTEIRA, "Físico", "Médico", 0) /* linha 1490 */
R(R_INTEIRA, "outrossim", "também", 0) /* linha 1491 */
R(R_INTEIRA, "Outrossim", "Também", 0) /* linha 1492 */
R(R_INTEIRA, "sobremaneira", "muito", 0) /* linha 1493 */
R(R_INTEIRA, "Sobremaneira", "Muito", 0) /* linha 1494 */
R(R_INTEIRA, "amiúde", "frequentemente", 0) /* linha 1495 */
R(R_INTEIRA, "Amiúde", "Frequentemente", 0) /* linha 1496 */
R(R_INTEIRA, "porventura", "acaso", 0) /* linha 1497 */
R(R_INTEIRA, "Porventura", "Acaso", 0) /* linha 1498 */
R(R_INTEIRA, "porquanto", "porque", 0) /* linha 1499 */
R(R_INTEIRA, "Porquanto", "Porque", 0) /* linha 1500 */
R(R_INTEIRA, "conquanto", "embora", 0) /* linha 1501 */
R(R_INTEIRA, "Conquanto", "Embora", 0) /* linha 1502 */
R(R_INTEIRA, "postoque", "embora", 0) /* linha 1503 */
R(R_INTEIRA, "Postoque", "Embora", 0) /* linha 1504 */
R(R_TEXTO, "de sorte que", "de modo que", 0) /* linha 1505 */
R(R_TEXTO, "De sorte que", "De modo que", 0) /* linha 1506 */
// 12. Revisão complementar pós-varredura e leitura (Lote 1 - Nov/2026)
// 12.1 Ditongos antigos (oi -> ou) e consoantes mudas (ct, pt)
R(R_INICIO, "oiro", "ouro", 0) /* linha 1510 */
R(R_INICIO, "Oiro", "Ouro", 0) /* linha 1511 */
R(R_INICIO, "coiro", "couro", 0) /* linha 1512 */
R(R_INICIO, "toiro", "touro", 0) /* linha 1513 */
R(R_INICIO, "calaboiço", "calabouço", 0) /* linha 1514 */
R(R_INTEIRA, "oiça", "ouça", 0) /* linha 1515 */
R(R_INTEIRA, "oiçam", "ouçam", 0) /* linha 1516 */
R(R_INICIO, "hemorrhoid", "hemorroid", 0) /* linha 1517 */
R(R_INICIO, "recto", "reto", 0) /* linha 1519 */
R(R_INICIO, "Recto", "Reto", 0) /* linha 1520 */
R(R_INICIO, "recta", "reta", 0) /* linha 1521 */
R(R_INICIO, "Recta", "Reta", 0) /* linha 1522 */
R(R_INICIO, "esculptur", "escultur", 0) /* linha 1523 */
R(R_INICIO, "auctor", "autor", 0) /* linha 1524 */
/* "aspecto" e "expectação" ficam como estão: no PT-BR o "c" se mantém */
R(R_INICIO, "excepto", "exceto", 0) /* linha 1526 */
R(R_INICIO, "tecto", "teto", 0) /* linha 1527 */
R(R_INICIO, "inspector", "inspetor", 0) /* linha 1528 */
R(R_INICIO, "dictado", "ditado", 0) /* linha 1529 */
R(R_INICIO, "espectaculo", "espetáculo", 1) /* linha 1530 */
R(R_INICIO, "facto", "fato", 0) /* linha 1531 */
R(R_INICIO, "aprompt", "apront", 0) /* linha 1532 */
R(R_INICIO, "districto", "distrito", 0) /* linha 1533 */
R(R_INICIO, "jactancia", "jactância", 1) /* linha 1534 */
R(R_INICIO, "interdicto", "interdito", 0) /* linha 1535 */
R(R_INICIO, "aqueducto", "aqueduto", 0) /* linha 1536 */
R(R_INICIO, "estructur", "estrutur", 0) /* linha 1537 */
R(R_INICIO, "indirect", "indiret", 0) /* linha 1538 */
R(R_INICIO, "conductor", "condutor", 0) /* linha 1539 */
// 12.2 Acentuação gráfica e vocabulário revisado
R(R_INICIO, "talamo", "tálamo", 1) /* linha 1542 */
R(R_INICIO, "heroe", "herói", 1) /* linha 1543 */
R(R_INICIO, "simplices", "símplices", 1) /* linha 1544 */
R(R_INICIO, "diluvio", "dilúvio", 1) /* linha 1545 */
R(R_INICIO, "silencio", "silêncio", 1) /* linha 1546 */
R(R_INICIO, "auxilio", "auxílio", 1) /* linha 1547 */
R(R_INICIO, "notorio", "notório", 1) /* linha 1548 */
R(R_INICIO, "psalterio", "saltério", 1) /* linha 1549 */
R(R_INICIO, "artificio", "artifício", 1) /* linha 1550 */
R(R_INICIO, "labio", "lábio", 1) /* linha 1551 */
R(R_INICIO, "divorcio", "divórcio", 1) /* linha 1552 */
R(R_INICIO, "premio", "prêmio", 1) /* linha 1553 */
R(R_INICIO, "sanguinario", "sanguinário", 1) /* linha 1554 */
R(R_INICIO, "repudio", "repúdio", 1) /* linha 1555 */
R(R_INICIO, "cilicio", "cilício", 1) /* linha 1556 */
R(R_INICIO, "arabio", "arábio", 1) /* linha 1557 */
R(R_INICIO, "vicio", "vício", 1) /* linha 1558 */
R(R_INICIO, "sitio", "sítio", 1) /* linha 1559 */
R(R_INICIO, "habitavel", "habitável", 1) /* linha 1560 */
R(R_INICIO, "historia", "história", 1) /* linha 1561 */
R(R_INICIO, "ante-hontem", "anteontem", 0) /* linha 1562 */
R(R_INICIO, "Hespanha", "Espanha", 0) /* linha 1563 */
R(R_INTEIRA, "alumia", "ilumina", 0) /* linha 1564 */
R(R_INTEIRA, "expurga-me", "limpa-me", 0) /* linha 1565 */
R(R_INTEIRA, "assenhoreiem", "tomem posse", 0) /* linha 1566 */
// 12.3 Nomes próprios e gentílicos bíblicos padronizados
R(R_INICIO, "Zebedeo", "Zebedeu", 0) /* linha 1569 */
R(R_INICIO, "amorrheo", "amorreu", 0) /* linha 1570 */
R(R_INICIO, "nazireo", "nazireu", 0) /* linha 1571 */
R(R_INICIO, "arameo", "arameu", 0) /* linha 1572 */
R(R_INICIO, "keneo", "queneu", 0) /* linha 1573 */
R(R_INICIO, "Keneo", "Queneu", 0) /* linha 1574 */
R(R_INICIO, "kenezeo", "quenezeu", 0) /* linha 1575 */
R(R_INICIO, "horeo", "horeu", 0) /* linha 1576 */
R(R_INICIO, "Horeo", "Horeu", 0) /* linha 1576 */
R(R_INICIO, "Heteo", "Heteu", 0) /* linha 1576 */
R(R_INICIO, "Hebron", "Hebrom", 0) /* linha 1577 */
R(R_INICIO, "Haman", "Hamã", 1) /* linha 1578 */
R(R_INICIO, "Hesbon", "Hesbom", 0) /* linha 1579 */
R(R_INICIO, "Hilkias", "Hilquias", 0) /* linha 1580 */
R(R_INICIO, "Haran", "Harã", 1) /* linha 1581 */
R(R_INICIO, "Horeb", "Horebe", 0) /* linha 1582 */
R(R_INICIO, "Heman", "Hemã", 1) /* linha 1583 */
R(R_INICIO, "Hezron", "Hezrom", 0) /* linha 1584 */
R(R_INICIO, "Hanun", "Hanum", 0) /* linha 1585 */
R(R_INICIO, "Habacuc", "Habacuque", 0) /* linha 1586 */
/* 9. Acertos finais da revisão de 11/2026 (só grafia, sem trocar palavras) */
R(R_TEXTO, "irreprehens", "irrepreens", 0) /* linha 1589 */
R(R_INTEIRA, "Siria", "Síria", 0) /* linha 1590 */
R(R_INTEIRA, "siros", "sírios", 0) /* linha 1590 */
R(R_INTEIRA, "Efeso", "Éfeso", 0) /* linha 1591 */
R(R_INTEIRA, "Tarsis", "Társis", 0) /* linha 1591 */
R(R_INTEIRA, "aflicto", "aflito", 0) /* linha 1592 */
R(R_INTEIRA, "aflicta", "aflita", 0) /* linha 1592 */
R(R_INTEIRA, "aflictos", "aflitos", 0) /* linha 1593 */
R(R_INTEIRA, "aflictas", "aflitas", 0) /* linha 1593 */
R(R_INTEIRA, "mirrha", "mirra", 0) /* linha 1594 */
R(R_INTEIRA, "oficio", "ofício", 0) /* linha 1595 */
R(R_INTEIRA, "oficios", "ofícios", 0) /* linha 1595 */
R(R_INTEIRA, "paralitico", "paralítico", 0) /* linha 1596 */
R(R_INTEIRA, "paraliticos", "paralíticos", 0) /* linha 1596 */
R(R_INTEIRA, "saduceos", "saduceus", 0) /* linha 1597 */
R(R_INTEIRA, "aneis", "anéis", 0) /* linha 1598 */
R(R_INTEIRA, "dificil", "difícil", 0) /* linha 1599 */
R(R_INTEIRA, "eficacia", "eficácia", 0) /* linha 1599 */
R(R_INTEIRA, "geteo", "geteu", 0) /* linha 1600 */
R(R_INTEIRA, "traír", "trair", 0) /* linha 1601 */
R(R_INTEIRA, "atraír", "atrair", 0) /* linha 1601 */
R(R_INTEIRA, "saír", "sair", 0) /* linha 1602 */
R(R_INTEIRA, "caír", "cair", 0) /* linha 1602 */
R(R_INTEIRA, "distraír", "distrair", 0) /* linha 1603 */
/* saiu, caiu, traiu, saindo, atrairei: sem acento */
R(R_TEXTO, "aíu", "aiu", 0) /* linha 1605 */
R(R_TEXTO, "aíndo", "aindo", 0) /* linha 1605 */
R(R_TEXTO, "aírei", "airei", 0) /* linha 1606 */
R(R_TEXTO, "aíremos", "airemos", 0) /* linha 1606 */
R(R_TEXTO, "aíria", "airia", 0) /* linha 1607 */
/* Leitura de 25/11/2026 (Gn 6, Mt 2) */
R(R_INTEIRA, "covado", "côvado", 0) /* linha 1609 */
R(R_INTEIRA, "dadiva", "dádiva", 0) /* linha 1610 */
R(R_INTEIRA, "dadivas", "dádivas", 0) /* linha 1610 */
R(R_TEXTO, "eis-que", "eis que", 0) /* linha 1611 */
R(R_TEXTO, "Eis-que", "Eis que", 0) /* linha 1611 */
R(R_INTEIRA, "Judah", "Judá", 0) /* linha 1612 */
/* Mesóclise antiga: far-lhe-has -> far-lhe-ás, dar-lhe-hemos -> dar-lhe-emos.
       Palavra inteira depois do hífen, para não tocar nomes como Maher-shalal-hash-baz. */
/* "-has" só depois de pronome (far-lhe-has -> far-lhe-ás); o "has" sozinho é "hás de" */
R(R_TEXTO, "-me-has", "-me-ás", 0) /* linha 1624 */
R(R_TEXTO, "-te-has", "-te-ás", 0) /* linha 1624 */
R(R_TEXTO, "-se-has", "-se-ás", 0) /* linha 1624 */
R(R_TEXTO, "-nos-has", "-nos-ás", 0) /* linha 1624 */
R(R_TEXTO, "-vos-has", "-vos-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lhe-has", "-lhe-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lhes-has", "-lhes-ás", 0) /* linha 1624 */
R(R_TEXTO, "-o-has", "-o-ás", 0) /* linha 1624 */
R(R_TEXTO, "-a-has", "-a-ás", 0) /* linha 1624 */
R(R_TEXTO, "-os-has", "-os-ás", 0) /* linha 1624 */
R(R_TEXTO, "-as-has", "-as-ás", 0) /* linha 1624 */
R(R_TEXTO, "-mo-has", "-mo-ás", 0) /* linha 1624 */
R(R_TEXTO, "-ma-has", "-ma-ás", 0) /* linha 1624 */
R(R_TEXTO, "-mos-has", "-mos-ás", 0) /* linha 1624 */
R(R_TEXTO, "-mas-has", "-mas-ás", 0) /* linha 1624 */
R(R_TEXTO, "-to-has", "-to-ás", 0) /* linha 1624 */
R(R_TEXTO, "-ta-has", "-ta-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lho-has", "-lho-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lha-has", "-lha-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lhos-has", "-lhos-ás", 0) /* linha 1624 */
R(R_TEXTO, "-lhas-has", "-lhas-ás", 0) /* linha 1624 */
R(R_INTEIRA, "has", "hás", 0) /* linha 1626 */
/* "has de" -> "hás de" */
R(R_INTEIRA, "hemos", "emos", 0) /* linha 1628 */
R(R_INTEIRA, "heis", "eis", 0) /* linha 1629 */
R(R_INTEIRA, "hia", "ia", 0) /* linha 1629 */
R(R_INTEIRA, "hias", "ias", 0) /* linha 1630 */
R(R_INTEIRA, "hiam", "iam", 0) /* linha 1630 */
/* Pronome no meio: leval-o-ás -> levá-lo-ás, restituil-os-ás -> restituí-los-ás */
R(R_TEXTO, "uil-o-ás", "uí-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "uil-o-eis", "uí-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "uil-o-emos", "uí-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "uil-o-ia", "uí-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "uil-o-ias", "uí-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "uil-o-iam", "uí-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-ás", "uí-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-eis", "uí-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-emos", "uí-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-ia", "uí-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-ias", "uí-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "uil-a-iam", "uí-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-ás", "uí-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-eis", "uí-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-emos", "uí-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-ia", "uí-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-ias", "uí-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "uil-os-iam", "uí-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-ás", "uí-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-eis", "uí-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-emos", "uí-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-ia", "uí-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-ias", "uí-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "uil-as-iam", "uí-las-iam", 0) /* linha 1643 */
R(R_TEXTO, "al-o-ás", "á-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "al-o-eis", "á-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "al-o-emos", "á-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "al-o-ia", "á-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "al-o-ias", "á-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "al-o-iam", "á-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "al-a-ás", "á-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "al-a-eis", "á-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "al-a-emos", "á-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "al-a-ia", "á-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "al-a-ias", "á-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "al-a-iam", "á-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "al-os-ás", "á-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "al-os-eis", "á-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "al-os-emos", "á-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "al-os-ia", "á-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "al-os-ias", "á-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "al-os-iam", "á-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "al-as-ás", "á-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "al-as-eis", "á-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "al-as-emos", "á-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "al-as-ia", "á-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "al-as-ias", "á-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "al-as-iam", "á-las-iam", 0) /* linha 1643 */
R(R_TEXTO, "el-o-ás", "ê-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "el-o-eis", "ê-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "el-o-emos", "ê-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "el-o-ia", "ê-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "el-o-ias", "ê-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "el-o-iam", "ê-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "el-a-ás", "ê-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "el-a-eis", "ê-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "el-a-emos", "ê-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "el-a-ia", "ê-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "el-a-ias", "ê-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "el-a-iam", "ê-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "el-os-ás", "ê-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "el-os-eis", "ê-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "el-os-emos", "ê-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "el-os-ia", "ê-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "el-os-ias", "ê-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "el-os-iam", "ê-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "el-as-ás", "ê-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "el-as-eis", "ê-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "el-as-emos", "ê-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "el-as-ia", "ê-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "el-as-ias", "ê-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "el-as-iam", "ê-las-iam", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-ás", "ô-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-eis", "ô-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-emos", "ô-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-ia", "ô-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-ias", "ô-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "ôl-o-iam", "ô-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-ás", "ô-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-eis", "ô-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-emos", "ô-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-ia", "ô-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-ias", "ô-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "ôl-a-iam", "ô-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-ás", "ô-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-eis", "ô-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-emos", "ô-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-ia", "ô-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-ias", "ô-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "ôl-os-iam", "ô-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-ás", "ô-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-eis", "ô-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-emos", "ô-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-ia", "ô-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-ias", "ô-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "ôl-as-iam", "ô-las-iam", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-ás", "ô-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-eis", "ô-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-emos", "ô-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-ia", "ô-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-ias", "ô-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "ol-o-iam", "ô-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-ás", "ô-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-eis", "ô-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-emos", "ô-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-ia", "ô-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-ias", "ô-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "ol-a-iam", "ô-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-ás", "ô-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-eis", "ô-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-emos", "ô-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-ia", "ô-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-ias", "ô-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "ol-os-iam", "ô-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-ás", "ô-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-eis", "ô-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-emos", "ô-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-ia", "ô-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-ias", "ô-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "ol-as-iam", "ô-las-iam", 0) /* linha 1643 */
R(R_TEXTO, "il-o-ás", "i-lo-ás", 0) /* linha 1643 */
R(R_TEXTO, "il-o-eis", "i-lo-eis", 0) /* linha 1643 */
R(R_TEXTO, "il-o-emos", "i-lo-emos", 0) /* linha 1643 */
R(R_TEXTO, "il-o-ia", "i-lo-ia", 0) /* linha 1643 */
R(R_TEXTO, "il-o-ias", "i-lo-ias", 0) /* linha 1643 */
R(R_TEXTO, "il-o-iam", "i-lo-iam", 0) /* linha 1643 */
R(R_TEXTO, "il-a-ás", "i-la-ás", 0) /* linha 1643 */
R(R_TEXTO, "il-a-eis", "i-la-eis", 0) /* linha 1643 */
R(R_TEXTO, "il-a-emos", "i-la-emos", 0) /* linha 1643 */
R(R_TEXTO, "il-a-ia", "i-la-ia", 0) /* linha 1643 */
R(R_TEXTO, "il-a-ias", "i-la-ias", 0) /* linha 1643 */
R(R_TEXTO, "il-a-iam", "i-la-iam", 0) /* linha 1643 */
R(R_TEXTO, "il-os-ás", "i-los-ás", 0) /* linha 1643 */
R(R_TEXTO, "il-os-eis", "i-los-eis", 0) /* linha 1643 */
R(R_TEXTO, "il-os-emos", "i-los-emos", 0) /* linha 1643 */
R(R_TEXTO, "il-os-ia", "i-los-ia", 0) /* linha 1643 */
R(R_TEXTO, "il-os-ias", "i-los-ias", 0) /* linha 1643 */
R(R_TEXTO, "il-os-iam", "i-los-iam", 0) /* linha 1643 */
R(R_TEXTO, "il-as-ás", "i-las-ás", 0) /* linha 1643 */
R(R_TEXTO, "il-as-eis", "i-las-eis", 0) /* linha 1643 */
R(R_TEXTO, "il-as-emos", "i-las-emos", 0) /* linha 1643 */
R(R_TEXTO, "il-as-ia", "i-las-ia", 0) /* linha 1643 */
R(R_TEXTO, "il-as-ias", "i-las-ias", 0) /* linha 1643 */
R(R_TEXTO, "il-as-iam", "i-las-iam", 0) /* linha 1643 */
/* Derivados de pôr: impozeram -> impuseram, propozera -> propusera */
R(R_TEXTO, "poze", "puse", 0) /* linha 1650 */
/* caluniar: o acento é só no substantivo "calúnia" */
R(R_TEXTO, "calúniad", "caluniad", 0) /* linha 1652 */
R(R_TEXTO, "calúniam", "caluniam", 0) /* linha 1652 */
R(R_TEXTO, "calúniando", "caluniando", 0) /* linha 1653 */
R(R_TEXTO, "calúnies", "calunies", 0) /* linha 1653 */
R(R_INTEIRA, "quiseramos", "quiséramos", 0) /* linha 1654 */
R(R_INTEIRA, "fossemos", "fôssemos", 0) /* linha 1654 */
R(R_INTEIRA, "fosseis", "fôsseis", 0) /* linha 1654 */
R(R_INTEIRA, "infíeis", "infiéis", 0) /* linha 1655 */
R(R_INTEIRA, "fíeis", "fiéis", 0) /* linha 1655 */
/* -iar no presente não leva acento: confiamos, gloriamos, desvieis */
R(R_INTEIRA, "confíamos", "confiamos", 0) /* linha 1657 */
R(R_INTEIRA, "gloríamos", "gloriamos", 0) /* linha 1657 */
R(R_INTEIRA, "desvíeis", "desvieis", 0) /* linha 1658 */
/* Pretérito forte leva acento agudo: tivésseis, tivéssemos */
R(R_TEXTO, "tivêss", "tivéss", 0) /* linha 1660 */
R(R_TEXTO, "Tivêss", "Tivéss", 0) /* linha 1660 */
R(R_TEXTO, "estivêss", "estivéss", 0) /* linha 1661 */
R(R_TEXTO, "houvêss", "houvéss", 0) /* linha 1661 */
R(R_TEXTO, "soubêss", "soubéss", 0) /* linha 1662 */
R(R_TEXTO, "quisêss", "quiséss", 0) /* linha 1662 */
R(R_TEXTO, "fizêss", "fizéss", 0) /* linha 1663 */
R(R_TEXTO, "pusêss", "puséss", 0) /* linha 1663 */
R(R_TEXTO, "dissêss", "disséss", 0) /* linha 1664 */
R(R_TEXTO, "trouxêss", "trouxéss", 0) /* linha 1664 */
R(R_TEXTO, "pudêss", "pudéss", 0) /* linha 1665 */
R(R_TEXTO, "coubêss", "coubéss", 0) /* linha 1665 */
/* 10. ZONA INVISÍVEL (varredura de 26/11/2026)
       Palavras que nenhuma regra acima trocava e que não existem no dicionário
       oficial pt-BR (VERO/LibreOffice). Cada par troca só a palavra inteira.
       Fonte: biblia-build/revisao/zona_todas.tsv + leitura no app. */
/* Leitura no app (26/11/2026) */
R(R_INTEIRA, "frecha", "flecha", 0) /* linha 1675 */
R(R_INTEIRA, "Frecha", "Flecha", 0) /* linha 1675 */
R(R_INTEIRA, "frechas", "flechas", 0) /* linha 1675 */
R(R_INTEIRA, "Frechas", "Flechas", 0) /* linha 1675 */
R(R_INTEIRA, "frecheiro", "flecheiro", 0) /* linha 1676 */
R(R_INTEIRA, "frecheiros", "flecheiros", 0) /* linha 1676 */
R(R_INTEIRA, "Frecheiros", "Flecheiros", 0) /* linha 1676 */
R(R_INTEIRA, "frecharam", "flecharam", 0) /* linha 1677 */
R(R_INTEIRA, "dum", "de um", 0) /* linha 1678 */
R(R_INTEIRA, "Dum", "De um", 0) /* linha 1678 */
R(R_INTEIRA, "duma", "de uma", 0) /* linha 1678 */
R(R_INTEIRA, "Duma", "De uma", 0) /* linha 1678 */
R(R_INTEIRA, "duns", "de uns", 0) /* linha 1679 */
R(R_INTEIRA, "dumas", "de umas", 0) /* linha 1679 */
R(R_INTEIRA, "Pamfilia", "Panfília", 0) /* linha 1680 */
R(R_INTEIRA, "Amfipolis", "Anfípolis", 0) /* linha 1680 */
R(R_INTEIRA, "numero", "número", 0) /* linha 1681 */
R(R_INTEIRA, "Numero", "Número", 0) /* linha 1681 */
R(R_INTEIRA, "numeros", "números", 0) /* linha 1681 */
/* Leitura no app: Gênesis 40-42 */
R(R_INTEIRA, "Canaan", "Canaã", 0) /* linha 1683 */
R(R_INTEIRA, "Manasseh", "Manassés", 0) /* linha 1683 */
R(R_INTEIRA, "Porem", "Porém", 0) /* linha 1683 */
/* Zona invisível 2: palavras certas sozinhas, mas sem acento no sentido do versículo */
R(R_INTEIRA, "numero", "número", 0) /* linha 1685 */
R(R_INTEIRA, "Numero", "Número", 0) /* linha 1685 */
R(R_INTEIRA, "pacifico", "pacífico", 0) /* linha 1686 */
R(R_INTEIRA, "Pacifico", "Pacífico", 0) /* linha 1686 */
R(R_INTEIRA, "estatua", "estátua", 0) /* linha 1687 */
R(R_INTEIRA, "Estatua", "Estátua", 0) /* linha 1687 */
R(R_INTEIRA, "oraculo", "oráculo", 0) /* linha 1688 */
R(R_INTEIRA, "Oraculo", "Oráculo", 0) /* linha 1688 */
R(R_INTEIRA, "figado", "fígado", 0) /* linha 1689 */
R(R_INTEIRA, "Figado", "Fígado", 0) /* linha 1689 */
R(R_INTEIRA, "astucia", "astúcia", 0) /* linha 1690 */
R(R_INTEIRA, "Astucia", "Astúcia", 0) /* linha 1690 */
R(R_INTEIRA, "impeto", "ímpeto", 0) /* linha 1691 */
R(R_INTEIRA, "Impeto", "Ímpeto", 0) /* linha 1691 */
R(R_INTEIRA, "espadua", "espádua", 0) /* linha 1692 */
R(R_INTEIRA, "Espadua", "Espádua", 0) /* linha 1692 */
R(R_INTEIRA, "ereis", "éreis", 0) /* linha 1693 */
R(R_INTEIRA, "Ereis", "Éreis", 0) /* linha 1693 */
R(R_INTEIRA, "noticia", "notícia", 0) /* linha 1694 */
R(R_INTEIRA, "Noticia", "Notícia", 0) /* linha 1694 */
R(R_INTEIRA, "divida", "dívida", 0) /* linha 1695 */
R(R_INTEIRA, "Divida", "Dívida", 0) /* linha 1695 */
R(R_INTEIRA, "credito", "crédito", 0) /* linha 1696 */
R(R_INTEIRA, "Credito", "Crédito", 0) /* linha 1696 */
R(R_INTEIRA, "copia", "cópia", 0) /* linha 1697 */
R(R_INTEIRA, "Copia", "Cópia", 0) /* linha 1697 */
R(R_INTEIRA, "medico", "médico", 0) /* linha 1698 */
R(R_INTEIRA, "Medico", "Médico", 0) /* linha 1698 */
R(R_INTEIRA, "copula", "cópula", 0) /* linha 1699 */
R(R_INTEIRA, "Copula", "Cópula", 0) /* linha 1699 */
R(R_INTEIRA, "dizimo", "dízimo", 0) /* linha 1700 */
R(R_INTEIRA, "Dizimo", "Dízimo", 0) /* linha 1700 */
R(R_INTEIRA, "deposito", "depósito", 0) /* linha 1701 */
R(R_INTEIRA, "Deposito", "Depósito", 0) /* linha 1701 */
R(R_INTEIRA, "macula", "mácula", 0) /* linha 1702 */
R(R_INTEIRA, "Macula", "Mácula", 0) /* linha 1702 */
R(R_INTEIRA, "osculo", "ósculo", 0) /* linha 1703 */
R(R_INTEIRA, "Osculo", "Ósculo", 0) /* linha 1703 */
R(R_INTEIRA, "prospero", "próspero", 0) /* linha 1704 */
R(R_INTEIRA, "Prospero", "Próspero", 0) /* linha 1704 */
R(R_INTEIRA, "balsamo", "bálsamo", 0) /* linha 1705 */
R(R_INTEIRA, "Balsamo", "Bálsamo", 0) /* linha 1705 */
R(R_INTEIRA, "milicia", "milícia", 0) /* linha 1706 */
R(R_INTEIRA, "Milicia", "Milícia", 0) /* linha 1706 */
R(R_INTEIRA, "ignominia", "ignomínia", 0) /* linha 1707 */
R(R_INTEIRA, "Ignominia", "Ignomínia", 0) /* linha 1707 */
R(R_INTEIRA, "titulo", "título", 0) /* linha 1708 */
R(R_INTEIRA, "Titulo", "Título", 0) /* linha 1708 */
R(R_INTEIRA, "estrepito", "estrépito", 0) /* linha 1709 */
R(R_INTEIRA, "Estrepito", "Estrépito", 0) /* linha 1709 */
R(R_INTEIRA, "estomago", "estômago", 0) /* linha 1710 */
R(R_INTEIRA, "Estomago", "Estômago", 0) /* linha 1710 */
R(R_INTEIRA, "abobada", "abóbada", 0) /* linha 1711 */
R(R_INTEIRA, "Abobada", "Abóbada", 0) /* linha 1711 */
R(R_INTEIRA, "vinculo", "vínculo", 0) /* linha 1712 */
R(R_INTEIRA, "Vinculo", "Vínculo", 0) /* linha 1712 */
R(R_INTEIRA, "magoa", "mágoa", 0) /* linha 1713 */
R(R_INTEIRA, "Magoa", "Mágoa", 0) /* linha 1713 */
R(R_INTEIRA, "viveres", "víveres", 0) /* linha 1714 */
R(R_INTEIRA, "Viveres", "Víveres", 0) /* linha 1714 */
R(R_INTEIRA, "adultero", "adúltero", 0) /* linha 1715 */
R(R_INTEIRA, "Adultero", "Adúltero", 0) /* linha 1715 */
R(R_INTEIRA, "ciume", "ciúme", 0) /* linha 1716 */
R(R_INTEIRA, "Ciume", "Ciúme", 0) /* linha 1716 */
R(R_INTEIRA, "alfandega", "alfândega", 0) /* linha 1717 */
R(R_INTEIRA, "Alfandega", "Alfândega", 0) /* linha 1717 */
R(R_INTEIRA, "citara", "cítara", 0) /* linha 1718 */
R(R_INTEIRA, "Citara", "Cítara", 0) /* linha 1718 */
R(R_INTEIRA, "alaude", "alaúde", 0) /* linha 1719 */
R(R_INTEIRA, "Alaude", "Alaúde", 0) /* linha 1719 */
R(R_INTEIRA, "arratel", "arrátel", 0) /* linha 1720 */
R(R_INTEIRA, "Arratel", "Arrátel", 0) /* linha 1720 */
R(R_INTEIRA, "solido", "sólido", 0) /* linha 1721 */
R(R_INTEIRA, "Solido", "Sólido", 0) /* linha 1721 */
R(R_INTEIRA, "alivio", "alívio", 0) /* linha 1722 */
R(R_INTEIRA, "Alivio", "Alívio", 0) /* linha 1722 */
R(R_INTEIRA, "hospede", "hóspede", 0) /* linha 1723 */
R(R_INTEIRA, "Hospede", "Hóspede", 0) /* linha 1723 */
R(R_INTEIRA, "calamo", "cálamo", 0) /* linha 1724 */
R(R_INTEIRA, "Calamo", "Cálamo", 0) /* linha 1724 */
R(R_INTEIRA, "regulo", "régulo", 0) /* linha 1725 */
R(R_INTEIRA, "Regulo", "Régulo", 0) /* linha 1725 */
R(R_INTEIRA, "lamina", "lâmina", 0) /* linha 1726 */
R(R_INTEIRA, "Lamina", "Lâmina", 0) /* linha 1726 */
R(R_INTEIRA, "aria", "ária", 0) /* linha 1727 */
R(R_INTEIRA, "Aria", "Ária", 0) /* linha 1727 */
R(R_INTEIRA, "vangloria", "vanglória", 0) /* linha 1728 */
R(R_INTEIRA, "Vangloria", "Vanglória", 0) /* linha 1728 */
R(R_INTEIRA, "propicio", "propício", 0) /* linha 1729 */
R(R_INTEIRA, "Propicio", "Propício", 0) /* linha 1729 */
R(R_INTEIRA, "ulcera", "úlcera", 0) /* linha 1730 */
R(R_INTEIRA, "Ulcera", "Úlcera", 0) /* linha 1730 */
R(R_INTEIRA, "matrimonio", "matrimônio", 0) /* linha 1731 */
R(R_INTEIRA, "Matrimonio", "Matrimônio", 0) /* linha 1731 */
R(R_INTEIRA, "ludibrio", "ludíbrio", 0) /* linha 1732 */
R(R_INTEIRA, "Ludibrio", "Ludíbrio", 0) /* linha 1732 */
R(R_INTEIRA, "cambio", "câmbio", 0) /* linha 1733 */
R(R_INTEIRA, "Cambio", "Câmbio", 0) /* linha 1733 */
R(R_INTEIRA, "tremulo", "trêmulo", 0) /* linha 1734 */
R(R_INTEIRA, "Tremulo", "Trêmulo", 0) /* linha 1734 */
R(R_INTEIRA, "valido", "válido", 0) /* linha 1735 */
R(R_INTEIRA, "Valido", "Válido", 0) /* linha 1735 */
R(R_INTEIRA, "insignia", "insígnia", 0) /* linha 1736 */
R(R_INTEIRA, "Insignia", "Insígnia", 0) /* linha 1736 */
R(R_INTEIRA, "legitimo", "legítimo", 0) /* linha 1737 */
R(R_INTEIRA, "Legitimo", "Legítimo", 0) /* linha 1737 */
R(R_INTEIRA, "enxundia", "enxúndia", 0) /* linha 1738 */
R(R_INTEIRA, "Enxundia", "Enxúndia", 0) /* linha 1738 */
R(R_INTEIRA, "concavo", "côncavo", 0) /* linha 1739 */
R(R_INTEIRA, "Concavo", "Côncavo", 0) /* linha 1739 */
R(R_INTEIRA, "fabula", "fábula", 0) /* linha 1740 */
R(R_INTEIRA, "Fabula", "Fábula", 0) /* linha 1740 */
R(R_INTEIRA, "litigio", "litígio", 0) /* linha 1741 */
R(R_INTEIRA, "Litigio", "Litígio", 0) /* linha 1741 */
R(R_INTEIRA, "bedelio", "bedélio", 0) /* linha 1742 */
R(R_INTEIRA, "Bedelio", "Bedélio", 0) /* linha 1742 */
R(R_INTEIRA, "trafico", "tráfico", 0) /* linha 1743 */
R(R_INTEIRA, "Trafico", "Tráfico", 0) /* linha 1743 */
R(R_INTEIRA, "vilipendio", "vilipêndio", 0) /* linha 1744 */
R(R_INTEIRA, "Vilipendio", "Vilipêndio", 0) /* linha 1744 */
R(R_INTEIRA, "absintio", "absíntio", 0) /* linha 1745 */
R(R_INTEIRA, "Absintio", "Absíntio", 0) /* linha 1745 */
R(R_INTEIRA, "mascara", "máscara", 0) /* linha 1746 */
R(R_INTEIRA, "Mascara", "Máscara", 0) /* linha 1746 */
R(R_INTEIRA, "arbitro", "árbitro", 0) /* linha 1747 */
R(R_INTEIRA, "Arbitro", "Árbitro", 0) /* linha 1747 */
R(R_INTEIRA, "nevoa", "névoa", 0) /* linha 1748 */
R(R_INTEIRA, "Nevoa", "Névoa", 0) /* linha 1748 */
R(R_INTEIRA, "indicio", "indício", 0) /* linha 1749 */
R(R_INTEIRA, "Indicio", "Indício", 0) /* linha 1749 */
R(R_INTEIRA, "sairam", "saíram", 0) /* linha 1750 */
R(R_INTEIRA, "Sairam", "Saíram", 0) /* linha 1751 */
R(R_INTEIRA, "cairam", "caíram", 0) /* linha 1752 */
R(R_INTEIRA, "Cairam", "Caíram", 0) /* linha 1753 */
R(R_INTEIRA, "cherubins", "querubins", 0) /* linha 1754 */
R(R_INTEIRA, "Cherubins", "Querubins", 0) /* linha 1755 */
R(R_INTEIRA, "juizes", "juízes", 0) /* linha 1756 */
R(R_INTEIRA, "Juizes", "Juízes", 0) /* linha 1757 */
R(R_INTEIRA, "parabola", "parábola", 0) /* linha 1758 */
R(R_INTEIRA, "Parabola", "Parábola", 0) /* linha 1759 */
R(R_INTEIRA, "devéras", "deveras", 0) /* linha 1760 */
R(R_INTEIRA, "Devéras", "Deveras", 0) /* linha 1761 */
R(R_INTEIRA, "carmezim", "carmesim", 0) /* linha 1762 */
R(R_INTEIRA, "Carmezim", "Carmesim", 0) /* linha 1763 */
R(R_INTEIRA, "dizimos", "dízimos", 0) /* linha 1764 */
R(R_INTEIRA, "Dizimos", "Dízimos", 0) /* linha 1765 */
R(R_INTEIRA, "cherubim", "querubim", 0) /* linha 1766 */
R(R_INTEIRA, "Cherubim", "Querubim", 0) /* linha 1767 */
R(R_INTEIRA, "pacificos", "pacíficos", 0) /* linha 1768 */
R(R_INTEIRA, "Pacificos", "Pacíficos", 0) /* linha 1769 */
R(R_INTEIRA, "destruiram", "destruíram", 0) /* linha 1770 */
R(R_INTEIRA, "Destruiram", "Destruíram", 0) /* linha 1771 */
R(R_INTEIRA, "incircumcisos", "incircuncisos", 0) /* linha 1772 */
R(R_INTEIRA, "Incircumcisos", "Incircuncisos", 0) /* linha 1773 */
R(R_INTEIRA, "jámais", "jamais", 0) /* linha 1774 */
R(R_INTEIRA, "Jámais", "Jamais", 0) /* linha 1775 */
R(R_INTEIRA, "brazas", "brasas", 0) /* linha 1776 */
R(R_INTEIRA, "Brazas", "Brasas", 0) /* linha 1777 */
R(R_INTEIRA, "parabolas", "parábolas", 0) /* linha 1778 */
R(R_INTEIRA, "Parabolas", "Parábolas", 0) /* linha 1779 */
R(R_INTEIRA, "côxa", "coxa", 0) /* linha 1780 */
R(R_INTEIRA, "Côxa", "Coxa", 0) /* linha 1781 */
R(R_INTEIRA, "incircumcisão", "incircuncisão", 0) /* linha 1782 */
R(R_INTEIRA, "Incircumcisão", "Incircuncisão", 0) /* linha 1783 */
R(R_INTEIRA, "unico", "único", 0) /* linha 1784 */
R(R_INTEIRA, "Unico", "Único", 0) /* linha 1785 */
R(R_INTEIRA, "relampagos", "relâmpagos", 0) /* linha 1786 */
R(R_INTEIRA, "Relampagos", "Relâmpagos", 0) /* linha 1787 */
R(R_INTEIRA, "escandalo", "escândalo", 0) /* linha 1788 */
R(R_INTEIRA, "Escandalo", "Escândalo", 0) /* linha 1789 */
R(R_INTEIRA, "sobreveiu", "sobreveio", 0) /* linha 1790 */
R(R_INTEIRA, "Sobreveiu", "Sobreveio", 0) /* linha 1791 */
R(R_INTEIRA, "aromatico", "aromático", 0) /* linha 1792 */
R(R_INTEIRA, "Aromatico", "Aromático", 0) /* linha 1793 */
R(R_INTEIRA, "côxo", "coxo", 0) /* linha 1794 */
R(R_INTEIRA, "Côxo", "Coxo", 0) /* linha 1795 */
R(R_INTEIRA, "incircumciso", "incircunciso", 0) /* linha 1796 */
R(R_INTEIRA, "Incircumciso", "Incircunciso", 0) /* linha 1797 */
R(R_INTEIRA, "destrui", "destruí", 0) /* linha 1798 */
R(R_INTEIRA, "Destrui", "Destruí", 0) /* linha 1799 */
R(R_INTEIRA, "saistes", "saístes", 0) /* linha 1800 */
R(R_INTEIRA, "Saistes", "Saístes", 0) /* linha 1801 */
R(R_INTEIRA, "possuiram", "possuíram", 0) /* linha 1802 */
R(R_INTEIRA, "Possuiram", "Possuíram", 0) /* linha 1803 */
R(R_INTEIRA, "proseguiu", "prosseguiu", 0) /* linha 1804 */
R(R_INTEIRA, "Proseguiu", "Prosseguiu", 0) /* linha 1805 */
R(R_INTEIRA, "montezes", "monteses", 0) /* linha 1806 */
R(R_INTEIRA, "Montezes", "Monteses", 0) /* linha 1807 */
R(R_INTEIRA, "cenaculo", "cenáculo", 0) /* linha 1808 */
R(R_INTEIRA, "Cenaculo", "Cenáculo", 0) /* linha 1809 */
R(R_INTEIRA, "destruirem", "destruírem", 0) /* linha 1810 */
R(R_INTEIRA, "Destruirem", "Destruírem", 0) /* linha 1811 */
R(R_INTEIRA, "tinheis", "tínheis", 0) /* linha 1812 */
R(R_INTEIRA, "Tinheis", "Tínheis", 0) /* linha 1813 */
R(R_INTEIRA, "saires", "saíres", 0) /* linha 1814 */
R(R_INTEIRA, "Saires", "Saíres", 0) /* linha 1815 */
R(R_INTEIRA, "leãosinho", "leãozinho", 0) /* linha 1816 */
R(R_INTEIRA, "Leãosinho", "Leãozinho", 0) /* linha 1817 */
R(R_INTEIRA, "saiste", "saíste", 0) /* linha 1818 */
R(R_INTEIRA, "Saiste", "Saíste", 0) /* linha 1819 */
R(R_INTEIRA, "adulteros", "adúlteros", 0) /* linha 1820 */
R(R_INTEIRA, "Adulteros", "Adúlteros", 0) /* linha 1821 */
R(R_INTEIRA, "deshonra", "desonra", 0) /* linha 1822 */
R(R_INTEIRA, "Deshonra", "Desonra", 0) /* linha 1823 */
R(R_INTEIRA, "cadeiasinhas", "cadeiazinhas", 0) /* linha 1824 */
R(R_INTEIRA, "Cadeiasinhas", "Cadeiazinhas", 0) /* linha 1825 */
R(R_INTEIRA, "remoe", "remói", 0) /* linha 1826 */
R(R_INTEIRA, "Remoe", "Remói", 0) /* linha 1827 */
R(R_INTEIRA, "mólho", "molho", 0) /* linha 1828 */
R(R_INTEIRA, "Mólho", "Molho", 0) /* linha 1829 */
R(R_INTEIRA, "prohibição", "proibição", 0) /* linha 1830 */
R(R_INTEIRA, "Prohibição", "Proibição", 0) /* linha 1831 */
R(R_INTEIRA, "côxos", "coxos", 0) /* linha 1832 */
R(R_INTEIRA, "Côxos", "Coxos", 0) /* linha 1833 */
R(R_INTEIRA, "rodea", "rodeia", 0) /* linha 1834 */
R(R_INTEIRA, "Rodea", "Rodeia", 0) /* linha 1835 */
R(R_INTEIRA, "montez", "montês", 0) /* linha 1836 */
R(R_INTEIRA, "Montez", "Montês", 0) /* linha 1837 */
R(R_INTEIRA, "alforge", "alforje", 0) /* linha 1838 */
R(R_INTEIRA, "Alforge", "Alforje", 0) /* linha 1839 */
R(R_INTEIRA, "sairem", "saírem", 0) /* linha 1840 */
R(R_INTEIRA, "Sairem", "Saírem", 0) /* linha 1841 */
R(R_INTEIRA, "ância", "ânsia", 0) /* linha 1842 */
R(R_INTEIRA, "Ância", "Ânsia", 0) /* linha 1843 */
R(R_INTEIRA, "relampago", "relâmpago", 0) /* linha 1844 */
R(R_INTEIRA, "Relampago", "Relâmpago", 0) /* linha 1845 */
R(R_INTEIRA, "creei", "criei", 0) /* linha 1846 */
R(R_INTEIRA, "Creei", "Criei", 0) /* linha 1847 */
R(R_INTEIRA, "unica", "única", 0) /* linha 1848 */
R(R_INTEIRA, "Unica", "Única", 0) /* linha 1849 */
R(R_INTEIRA, "sairam-lhe", "saíram-lhe", 0) /* linha 1850 */
R(R_INTEIRA, "Sairam-lhe", "Saíram-lhe", 0) /* linha 1851 */
R(R_INTEIRA, "saira", "saíra", 0) /* linha 1852 */
R(R_INTEIRA, "Saira", "Saíra", 0) /* linha 1853 */
R(R_INTEIRA, "possuires", "possuíres", 0) /* linha 1854 */
R(R_INTEIRA, "Possuires", "Possuíres", 0) /* linha 1855 */
R(R_INTEIRA, "medicos", "médicos", 0) /* linha 1856 */
R(R_INTEIRA, "Medicos", "Médicos", 0) /* linha 1857 */
R(R_INTEIRA, "reteem", "retêm", 0) /* linha 1858 */
R(R_INTEIRA, "Reteem", "Retêm", 0) /* linha 1859 */
R(R_INTEIRA, "possuia", "possuía", 0) /* linha 1860 */
R(R_INTEIRA, "Possuia", "Possuía", 0) /* linha 1861 */
R(R_INTEIRA, "exhortação", "exortação", 0) /* linha 1862 */
R(R_INTEIRA, "Exhortação", "Exortação", 0) /* linha 1863 */
R(R_INTEIRA, "adultéra", "adúltera", 0) /* linha 1864 */
R(R_INTEIRA, "Adultéra", "Adúltera", 0) /* linha 1865 */
R(R_INTEIRA, "féras", "feras", 0) /* linha 1866 */
R(R_INTEIRA, "Féras", "Feras", 0) /* linha 1867 */
R(R_INTEIRA, "exhorta", "exorta", 0) /* linha 1868 */
R(R_INTEIRA, "Exhorta", "Exorta", 0) /* linha 1869 */
R(R_INTEIRA, "notoria", "notória", 0) /* linha 1870 */
R(R_INTEIRA, "Notoria", "Notória", 0) /* linha 1871 */
R(R_INTEIRA, "escandalos", "escândalos", 0) /* linha 1872 */
R(R_INTEIRA, "Escandalos", "Escândalos", 0) /* linha 1873 */
R(R_INTEIRA, "sauda", "saúda", 0) /* linha 1874 */
R(R_INTEIRA, "Sauda", "Saúda", 0) /* linha 1875 */
R(R_INTEIRA, "ishmaelitas", "ismaelitas", 0) /* linha 1876 */
R(R_INTEIRA, "Ishmaelitas", "Ismaelitas", 0) /* linha 1877 */
R(R_INTEIRA, "adopção", "adoção", 0) /* linha 1878 */
R(R_INTEIRA, "Adopção", "Adoção", 0) /* linha 1879 */
R(R_INTEIRA, "leõesinhos", "leõezinhos", 0) /* linha 1880 */
R(R_INTEIRA, "Leõesinhos", "Leõezinhos", 0) /* linha 1881 */
R(R_INTEIRA, "pifaro", "pífaro", 0) /* linha 1882 */
R(R_INTEIRA, "Pifaro", "Pífaro", 0) /* linha 1883 */
R(R_INTEIRA, "cubiça", "cobiça", 0) /* linha 1884 */
R(R_INTEIRA, "Cubiça", "Cobiça", 0) /* linha 1885 */
R(R_INTEIRA, "saimos", "saímos", 0) /* linha 1886 */
R(R_INTEIRA, "Saimos", "Saímos", 0) /* linha 1887 */
R(R_INTEIRA, "aromaticas", "aromáticas", 0) /* linha 1888 */
R(R_INTEIRA, "Aromaticas", "Aromáticas", 0) /* linha 1889 */
R(R_INTEIRA, "vêl-o", "vê-lo", 0) /* linha 1890 */
R(R_INTEIRA, "Vêl-o", "Vê-lo", 0) /* linha 1891 */
R(R_INTEIRA, "aromatica", "aromática", 0) /* linha 1892 */
R(R_INTEIRA, "Aromatica", "Aromática", 0) /* linha 1893 */
R(R_INTEIRA, "efesios", "efésios", 0) /* linha 1894 */
R(R_INTEIRA, "Efesios", "Efésios", 0) /* linha 1895 */
R(R_INTEIRA, "brazeiros", "braseiros", 0) /* linha 1896 */
R(R_INTEIRA, "Brazeiros", "Braseiros", 0) /* linha 1897 */
R(R_INTEIRA, "alem", "além", 0) /* linha 1898 */
R(R_INTEIRA, "Alem", "Além", 0) /* linha 1899 */
R(R_INTEIRA, "destruiste", "destruíste", 0) /* linha 1900 */
R(R_INTEIRA, "Destruiste", "Destruíste", 0) /* linha 1901 */
R(R_INTEIRA, "espivitadores", "espevitadores", 0) /* linha 1902 */
R(R_INTEIRA, "Espivitadores", "Espevitadores", 0) /* linha 1903 */
R(R_INTEIRA, "proconsul", "procônsul", 0) /* linha 1904 */
R(R_INTEIRA, "Proconsul", "Procônsul", 0) /* linha 1905 */
R(R_INTEIRA, "afectuosamente", "afetuosamente", 0) /* linha 1906 */
R(R_INTEIRA, "Afectuosamente", "Afetuosamente", 0) /* linha 1907 */
R(R_INTEIRA, "anuncíamos", "anunciamos", 0) /* linha 1908 */
R(R_INTEIRA, "Anuncíamos", "Anunciamos", 0) /* linha 1909 */
R(R_INTEIRA, "exhortar", "exortar", 0) /* linha 1910 */
R(R_INTEIRA, "Exhortar", "Exortar", 0) /* linha 1911 */
R(R_INTEIRA, "brazeiro", "braseiro", 0) /* linha 1912 */
R(R_INTEIRA, "Brazeiro", "Braseiro", 0) /* linha 1913 */
R(R_INTEIRA, "cananea", "cananeia", 0) /* linha 1914 */
R(R_INTEIRA, "Cananea", "Cananeia", 0) /* linha 1915 */
R(R_INTEIRA, "pertência", "pertencia", 0) /* linha 1916 */
R(R_INTEIRA, "Pertência", "Pertencia", 0) /* linha 1917 */
R(R_INTEIRA, "hebreas", "hebreias", 0) /* linha 1918 */
R(R_INTEIRA, "Hebreas", "Hebreias", 0) /* linha 1919 */
R(R_INTEIRA, "constituiram", "constituíram", 0) /* linha 1920 */
R(R_INTEIRA, "Constituiram", "Constituíram", 0) /* linha 1921 */
R(R_INTEIRA, "himno", "hino", 0) /* linha 1922 */
R(R_INTEIRA, "Himno", "Hino", 0) /* linha 1923 */
R(R_INTEIRA, "saissem", "saíssem", 0) /* linha 1924 */
R(R_INTEIRA, "Saissem", "Saíssem", 0) /* linha 1925 */
R(R_INTEIRA, "cubiçarás", "cobiçarás", 0) /* linha 1926 */
R(R_INTEIRA, "Cubiçarás", "Cobiçarás", 0) /* linha 1927 */
R(R_INTEIRA, "carbunculo", "carbúnculo", 0) /* linha 1928 */
R(R_INTEIRA, "Carbunculo", "Carbúnculo", 0) /* linha 1929 */
R(R_INTEIRA, "pavez", "pavês", 0) /* linha 1930 */
R(R_INTEIRA, "Pavez", "Pavês", 0) /* linha 1931 */
R(R_INTEIRA, "cireneo", "cireneu", 0) /* linha 1932 */
R(R_INTEIRA, "Cireneo", "Cireneu", 0) /* linha 1933 */
R(R_INTEIRA, "rodeam", "rodeiam", 0) /* linha 1934 */
R(R_INTEIRA, "Rodeam", "Rodeiam", 0) /* linha 1935 */
R(R_INTEIRA, "confíeis", "confieis", 0) /* linha 1936 */
R(R_INTEIRA, "Confíeis", "Confieis", 0) /* linha 1937 */
R(R_INTEIRA, "aquem", "aquém", 0) /* linha 1938 */
R(R_INTEIRA, "Aquem", "Aquém", 0) /* linha 1939 */
R(R_INTEIRA, "caiste", "caíste", 0) /* linha 1940 */
R(R_INTEIRA, "Caiste", "Caíste", 0) /* linha 1941 */
R(R_INTEIRA, "pavezes", "paveses", 0) /* linha 1942 */
R(R_INTEIRA, "Pavezes", "Paveses", 0) /* linha 1943 */
R(R_INTEIRA, "matemô-lo", "matemo-lo", 0) /* linha 1944 */
R(R_INTEIRA, "Matemô-lo", "Matemo-lo", 0) /* linha 1945 */
R(R_INTEIRA, "sanguinaria", "sanguinária", 0) /* linha 1946 */
R(R_INTEIRA, "Sanguinaria", "Sanguinária", 0) /* linha 1947 */
R(R_INTEIRA, "exhortamos", "exortamos", 0) /* linha 1948 */
R(R_INTEIRA, "Exhortamos", "Exortamos", 0) /* linha 1949 */
R(R_INTEIRA, "leval-os-á", "levá-los-á", 0) /* linha 1950 */
R(R_INTEIRA, "Leval-os-á", "Levá-los-á", 0) /* linha 1951 */
R(R_INTEIRA, "cubiçosos", "cobiçosos", 0) /* linha 1952 */
R(R_INTEIRA, "Cubiçosos", "Cobiçosos", 0) /* linha 1953 */
R(R_INTEIRA, "circunvisinhas", "circunvizinhas", 0) /* linha 1954 */
R(R_INTEIRA, "Circunvisinhas", "Circunvizinhas", 0) /* linha 1955 */
R(R_INTEIRA, "revéz", "revés", 0) /* linha 1956 */
R(R_INTEIRA, "Revéz", "Revés", 0) /* linha 1957 */
R(R_INTEIRA, "cubices", "cobices", 0) /* linha 1958 */
R(R_INTEIRA, "Cubices", "Cobices", 0) /* linha 1959 */
R(R_INTEIRA, "tinhamos", "tínhamos", 0) /* linha 1960 */
R(R_INTEIRA, "Tinhamos", "Tínhamos", 0) /* linha 1961 */
R(R_INTEIRA, "sêlo", "selo", 0) /* linha 1962 */
R(R_INTEIRA, "Sêlo", "Selo", 0) /* linha 1963 */
R(R_INTEIRA, "prohibais", "proibais", 0) /* linha 1964 */
R(R_INTEIRA, "Prohibais", "Proibais", 0) /* linha 1965 */
R(R_INTEIRA, "cordeis", "cordéis", 0) /* linha 1966 */
R(R_INTEIRA, "Cordeis", "Cordéis", 0) /* linha 1967 */
R(R_INTEIRA, "seguí-lo", "segui-lo", 0) /* linha 1968 */
R(R_INTEIRA, "Seguí-lo", "Segui-lo", 0) /* linha 1969 */
R(R_INTEIRA, "destruisse", "destruísse", 0) /* linha 1970 */
R(R_INTEIRA, "Destruisse", "Destruísse", 0) /* linha 1971 */
R(R_INTEIRA, "inuteis", "inúteis", 0) /* linha 1972 */
R(R_INTEIRA, "Inuteis", "Inúteis", 0) /* linha 1973 */
R(R_INTEIRA, "himnos", "hinos", 0) /* linha 1974 */
R(R_INTEIRA, "Himnos", "Hinos", 0) /* linha 1975 */
R(R_INTEIRA, "pôrem", "porem", 0) /* linha 1976 */
R(R_INTEIRA, "Pôrem", "Porem", 0) /* linha 1977 */
R(R_INTEIRA, "dificeis", "difíceis", 0) /* linha 1978 */
R(R_INTEIRA, "Dificeis", "Difíceis", 0) /* linha 1979 */
R(R_INTEIRA, "possuirem", "possuírem", 0) /* linha 1980 */
R(R_INTEIRA, "Possuirem", "Possuírem", 0) /* linha 1981 */
R(R_INTEIRA, "satrapas", "sátrapas", 0) /* linha 1982 */
R(R_INTEIRA, "Satrapas", "Sátrapas", 0) /* linha 1983 */
R(R_INTEIRA, "esmiuça", "esmiúça", 0) /* linha 1984 */
R(R_INTEIRA, "Esmiuça", "Esmiúça", 0) /* linha 1985 */
R(R_INTEIRA, "grangeou", "granjeou", 0) /* linha 1986 */
R(R_INTEIRA, "Grangeou", "Granjeou", 0) /* linha 1987 */
R(R_INTEIRA, "antehontem", "anteontem", 0) /* linha 1988 */
R(R_INTEIRA, "Antehontem", "Anteontem", 0) /* linha 1989 */
R(R_INTEIRA, "simfonia", "sinfonia", 0) /* linha 1990 */
R(R_INTEIRA, "Simfonia", "Sinfonia", 0) /* linha 1991 */
R(R_INTEIRA, "nóra", "nora", 0) /* linha 1992 */
R(R_INTEIRA, "Nóra", "Nora", 0) /* linha 1993 */
R(R_INTEIRA, "dextros", "destros", 0) /* linha 1994 */
R(R_INTEIRA, "Dextros", "Destros", 0) /* linha 1995 */
R(R_INTEIRA, "saisse", "saísse", 0) /* linha 1996 */
R(R_INTEIRA, "Saisse", "Saísse", 0) /* linha 1997 */
R(R_INTEIRA, "espadoa", "espádua", 0) /* linha 1998 */
R(R_INTEIRA, "Espadoa", "Espádua", 0) /* linha 1999 */
R(R_INTEIRA, "furia", "fúria", 0) /* linha 2000 */
R(R_INTEIRA, "Furia", "Fúria", 0) /* linha 2001 */
R(R_INTEIRA, "efrateo", "efrateu", 0) /* linha 2002 */
R(R_INTEIRA, "Efrateo", "Efrateu", 0) /* linha 2003 */
R(R_INTEIRA, "destruissem", "destruíssem", 0) /* linha 2004 */
R(R_INTEIRA, "Destruissem", "Destruíssem", 0) /* linha 2005 */
R(R_INTEIRA, "opéra", "opera", 0) /* linha 2006 */
R(R_INTEIRA, "Opéra", "Opera", 0) /* linha 2007 */
R(R_INTEIRA, "siriaco", "siríaco", 0) /* linha 2008 */
R(R_INTEIRA, "Siriaco", "Siríaco", 0) /* linha 2009 */
R(R_INTEIRA, "caira", "caíra", 0) /* linha 2010 */
R(R_INTEIRA, "Caira", "Caíra", 0) /* linha 2011 */
R(R_INTEIRA, "libios", "líbios", 0) /* linha 2012 */
R(R_INTEIRA, "Libios", "Líbios", 0) /* linha 2013 */
R(R_INTEIRA, "pôpa", "popa", 0) /* linha 2014 */
R(R_INTEIRA, "Pôpa", "Popa", 0) /* linha 2015 */
R(R_INTEIRA, "exhortava", "exortava", 0) /* linha 2016 */
R(R_INTEIRA, "Exhortava", "Exortava", 0) /* linha 2017 */
R(R_INTEIRA, "hetea", "heteia", 0) /* linha 2018 */
R(R_INTEIRA, "Hetea", "Heteia", 0) /* linha 2019 */
R(R_INTEIRA, "ponteagudas", "pontiagudas", 0) /* linha 2020 */
R(R_INTEIRA, "Ponteagudas", "Pontiagudas", 0) /* linha 2021 */
R(R_INTEIRA, "circunvisinha", "circunvizinha", 0) /* linha 2022 */
R(R_INTEIRA, "Circunvisinha", "Circunvizinha", 0) /* linha 2023 */
R(R_INTEIRA, "sobresairam", "sobressaíram", 0) /* linha 2024 */
R(R_INTEIRA, "Sobresairam", "Sobressaíram", 0) /* linha 2025 */
R(R_INTEIRA, "exhortai-vos", "exortai-vos", 0) /* linha 2026 */
R(R_INTEIRA, "Exhortai-vos", "Exortai-vos", 0) /* linha 2027 */
R(R_INTEIRA, "ácêrca", "acerca", 0) /* linha 2028 */
R(R_INTEIRA, "Ácêrca", "Acerca", 0) /* linha 2029 */
R(R_INTEIRA, "prosigo", "prossigo", 0) /* linha 2030 */
R(R_INTEIRA, "Prosigo", "Prossigo", 0) /* linha 2031 */
R(R_INTEIRA, "destruia", "destruía", 0) /* linha 2032 */
R(R_INTEIRA, "Destruia", "Destruía", 0) /* linha 2033 */
R(R_INTEIRA, "tôa", "toa", 0) /* linha 2034 */
R(R_INTEIRA, "Tôa", "Toa", 0) /* linha 2035 */
R(R_INTEIRA, "triumfar", "triunfar", 0) /* linha 2036 */
R(R_INTEIRA, "Triumfar", "Triunfar", 0) /* linha 2037 */
R(R_INTEIRA, "pozêsseis", "pusésseis", 0) /* linha 2038 */
R(R_INTEIRA, "Pozêsseis", "Pusésseis", 0) /* linha 2039 */
R(R_INTEIRA, "chôro", "choro", 0) /* linha 2040 */
R(R_INTEIRA, "Chôro", "Choro", 0) /* linha 2041 */
R(R_INTEIRA, "deminuirá", "diminuirá", 0) /* linha 2042 */
R(R_INTEIRA, "Deminuirá", "Diminuirá", 0) /* linha 2043 */
R(R_INTEIRA, "bahia", "baía", 0) /* linha 2044 */
R(R_INTEIRA, "Bahia", "Baía", 0) /* linha 2045 */
R(R_INTEIRA, "vehemência", "veemência", 0) /* linha 2046 */
R(R_INTEIRA, "Vehemência", "Veemência", 0) /* linha 2047 */
R(R_INTEIRA, "eguas", "éguas", 0) /* linha 2048 */
R(R_INTEIRA, "Eguas", "Éguas", 0) /* linha 2049 */
R(R_INTEIRA, "cairem", "caírem", 0) /* linha 2050 */
R(R_INTEIRA, "Cairem", "Caírem", 0) /* linha 2051 */
R(R_INTEIRA, "exhortando-os", "exortando-os", 0) /* linha 2052 */
R(R_INTEIRA, "Exhortando-os", "Exortando-os", 0) /* linha 2053 */
R(R_INTEIRA, "gloría-se", "gloria-se", 0) /* linha 2054 */
R(R_INTEIRA, "Gloría-se", "Gloria-se", 0) /* linha 2055 */
R(R_INTEIRA, "hebrea", "hebreia", 0) /* linha 2056 */
R(R_INTEIRA, "Hebrea", "Hebreia", 0) /* linha 2057 */
R(R_INTEIRA, "despojemô-los", "despojemo-los", 0) /* linha 2058 */
R(R_INTEIRA, "Despojemô-los", "Despojemo-los", 0) /* linha 2059 */
R(R_INTEIRA, "destruira", "destruíra", 0) /* linha 2060 */
R(R_INTEIRA, "Destruira", "Destruíra", 0) /* linha 2061 */
R(R_INTEIRA, "infrutifera", "infrutífera", 0) /* linha 2062 */
R(R_INTEIRA, "Infrutifera", "Infrutífera", 0) /* linha 2063 */
R(R_INTEIRA, "coherdeiros", "coerdeiros", 0) /* linha 2064 */
R(R_INTEIRA, "Coherdeiros", "Coerdeiros", 0) /* linha 2065 */
R(R_INTEIRA, "constituiste", "constituíste", 0) /* linha 2066 */
R(R_INTEIRA, "Constituiste", "Constituíste", 0) /* linha 2067 */
R(R_INTEIRA, "afecto", "afeto", 0) /* linha 2068 */
R(R_INTEIRA, "Afecto", "Afeto", 0) /* linha 2069 */
R(R_INTEIRA, "prohibimos", "proibimos", 0) /* linha 2070 */
R(R_INTEIRA, "Prohibimos", "Proibimos", 0) /* linha 2071 */
R(R_INTEIRA, "leôa", "leoa", 0) /* linha 2072 */
R(R_INTEIRA, "Leôa", "Leoa", 0) /* linha 2073 */
R(R_INTEIRA, "cantámos-vos", "cantamos-vos", 0) /* linha 2074 */
R(R_INTEIRA, "Cantámos-vos", "Cantamos-vos", 0) /* linha 2075 */
R(R_INTEIRA, "alforges", "alforjes", 0) /* linha 2076 */
R(R_INTEIRA, "Alforges", "Alforjes", 0) /* linha 2077 */
R(R_INTEIRA, "efectuar", "efetuar", 0) /* linha 2078 */
R(R_INTEIRA, "Efectuar", "Efetuar", 0) /* linha 2079 */
R(R_INTEIRA, "lidios", "lídios", 0) /* linha 2080 */
R(R_INTEIRA, "Lidios", "Lídios", 0) /* linha 2081 */
R(R_INTEIRA, "prestimo", "préstimo", 0) /* linha 2082 */
R(R_INTEIRA, "Prestimo", "Préstimo", 0) /* linha 2083 */
R(R_INTEIRA, "cenaculos", "cenáculos", 0) /* linha 2084 */
R(R_INTEIRA, "Cenaculos", "Cenáculos", 0) /* linha 2085 */
R(R_INTEIRA, "notorias", "notórias", 0) /* linha 2086 */
R(R_INTEIRA, "Notorias", "Notórias", 0) /* linha 2087 */
R(R_INTEIRA, "recrea", "recreia", 0) /* linha 2088 */
R(R_INTEIRA, "Recrea", "Recreia", 0) /* linha 2089 */
R(R_INTEIRA, "arabe", "árabe", 0) /* linha 2090 */
R(R_INTEIRA, "Arabe", "Árabe", 0) /* linha 2091 */
R(R_INTEIRA, "âncias", "ânsias", 0) /* linha 2092 */
R(R_INTEIRA, "Âncias", "Ânsias", 0) /* linha 2093 */
R(R_INTEIRA, "prôa", "proa", 0) /* linha 2094 */
R(R_INTEIRA, "Prôa", "Proa", 0) /* linha 2095 */
R(R_INTEIRA, "frutiferos", "frutíferos", 0) /* linha 2096 */
R(R_INTEIRA, "Frutiferos", "Frutíferos", 0) /* linha 2097 */
R(R_INTEIRA, "resoará", "ressoará", 0) /* linha 2098 */
R(R_INTEIRA, "Resoará", "Ressoará", 0) /* linha 2099 */
R(R_INTEIRA, "sêlos", "selos", 0) /* linha 2100 */
R(R_INTEIRA, "Sêlos", "Selos", 0) /* linha 2101 */
R(R_INTEIRA, "frutifero", "frutífero", 0) /* linha 2102 */
R(R_INTEIRA, "Frutifero", "Frutífero", 0) /* linha 2103 */
R(R_INTEIRA, "roe", "rói", 0) /* linha 2104 */
R(R_INTEIRA, "Roe", "Rói", 0) /* linha 2105 */
R(R_INTEIRA, "gloría", "gloria", 0) /* linha 2106 */
R(R_INTEIRA, "Gloría", "Gloria", 0) /* linha 2107 */
R(R_INTEIRA, "sobresaltados", "sobressaltados", 0) /* linha 2108 */
R(R_INTEIRA, "Sobresaltados", "Sobressaltados", 0) /* linha 2109 */
R(R_INTEIRA, "desterco", "esterco", 0) /* linha 2110 */
R(R_INTEIRA, "Desterco", "Esterco", 0) /* linha 2111 */
R(R_INTEIRA, "proseguirei", "prosseguirei", 0) /* linha 2112 */
R(R_INTEIRA, "Proseguirei", "Prosseguirei", 0) /* linha 2113 */
R(R_INTEIRA, "ishmaelita", "ismaelita", 0) /* linha 2114 */
R(R_INTEIRA, "Ishmaelita", "Ismaelita", 0) /* linha 2115 */
R(R_INTEIRA, "incômodes", "incomodes", 0) /* linha 2116 */
R(R_INTEIRA, "Incômodes", "Incomodes", 0) /* linha 2117 */
R(R_INTEIRA, "grangeei", "granjeei", 0) /* linha 2118 */
R(R_INTEIRA, "Grangeei", "Granjeei", 0) /* linha 2119 */
R(R_INTEIRA, "judaismo", "judaísmo", 0) /* linha 2120 */
R(R_INTEIRA, "Judaismo", "Judaísmo", 0) /* linha 2121 */
R(R_INTEIRA, "quéda", "queda", 0) /* linha 2122 */
R(R_INTEIRA, "Quéda", "Queda", 0) /* linha 2123 */
R(R_INTEIRA, "descairam", "decaíram", 0) /* linha 2124 */
R(R_INTEIRA, "Descairam", "Decaíram", 0) /* linha 2125 */
R(R_INTEIRA, "impuzer", "impuser", 0) /* linha 2126 */
R(R_INTEIRA, "Impuzer", "Impuser", 0) /* linha 2127 */
R(R_INTEIRA, "agata", "ágata", 0) /* linha 2128 */
R(R_INTEIRA, "Agata", "Ágata", 0) /* linha 2129 */
R(R_INTEIRA, "creíamos", "creiamos", 0) /* linha 2130 */
R(R_INTEIRA, "Creíamos", "Creiamos", 0) /* linha 2131 */
R(R_INTEIRA, "caisse", "caísse", 0) /* linha 2132 */
R(R_INTEIRA, "Caisse", "Caísse", 0) /* linha 2133 */
R(R_INTEIRA, "envíeis", "envieis", 0) /* linha 2134 */
R(R_INTEIRA, "Envíeis", "Envieis", 0) /* linha 2135 */
R(R_INTEIRA, "crédor", "credor", 0) /* linha 2136 */
R(R_INTEIRA, "Crédor", "Credor", 0) /* linha 2137 */
R(R_INTEIRA, "extasis", "êxtase", 0) /* linha 2138 */
R(R_INTEIRA, "Extasis", "Êxtase", 0) /* linha 2139 */
R(R_INTEIRA, "envíamos", "enviamos", 0) /* linha 2140 */
R(R_INTEIRA, "Envíamos", "Enviamos", 0) /* linha 2141 */
R(R_INTEIRA, "assocíeis", "associeis", 0) /* linha 2142 */
R(R_INTEIRA, "Assocíeis", "Associeis", 0) /* linha 2143 */
R(R_INTEIRA, "distribuirem", "distribuírem", 0) /* linha 2144 */
R(R_INTEIRA, "Distribuirem", "Distribuírem", 0) /* linha 2145 */
R(R_INTEIRA, "contribuiram", "contribuíram", 0) /* linha 2146 */
R(R_INTEIRA, "Contribuiram", "Contribuíram", 0) /* linha 2147 */
R(R_INTEIRA, "feiticerias", "feitiçarias", 0) /* linha 2148 */
R(R_INTEIRA, "Feiticerias", "Feitiçarias", 0) /* linha 2149 */
R(R_INTEIRA, "mórmente", "mormente", 0) /* linha 2150 */
R(R_INTEIRA, "Mórmente", "Mormente", 0) /* linha 2151 */
R(R_INTEIRA, "leviticos", "levíticos", 0) /* linha 2152 */
R(R_INTEIRA, "Leviticos", "Levíticos", 0) /* linha 2153 */
R(R_INTEIRA, "peze", "pese", 0) /* linha 2154 */
R(R_INTEIRA, "Peze", "Pese", 0) /* linha 2155 */
R(R_INTEIRA, "retens", "reténs", 0) /* linha 2156 */
R(R_INTEIRA, "Retens", "Reténs", 0) /* linha 2157 */
R(R_INTEIRA, "menea", "meneia", 0) /* linha 2158 */
R(R_INTEIRA, "Menea", "Meneia", 0) /* linha 2159 */
R(R_INTEIRA, "mólhos", "molhos", 0) /* linha 2160 */
R(R_INTEIRA, "Mólhos", "Molhos", 0) /* linha 2161 */
R(R_INTEIRA, "arduas", "árduas", 0) /* linha 2162 */
R(R_INTEIRA, "Arduas", "Árduas", 0) /* linha 2163 */
R(R_INTEIRA, "mortifera", "mortífera", 0) /* linha 2164 */
R(R_INTEIRA, "Mortifera", "Mortífera", 0) /* linha 2165 */
R(R_INTEIRA, "braza", "brasa", 0) /* linha 2166 */
R(R_INTEIRA, "Braza", "Brasa", 0) /* linha 2167 */
R(R_INTEIRA, "exhortar-vos", "exortar-vos", 0) /* linha 2168 */
R(R_INTEIRA, "Exhortar-vos", "Exortar-vos", 0) /* linha 2169 */
R(R_INTEIRA, "cubiçoso", "cobiçoso", 0) /* linha 2170 */
R(R_INTEIRA, "Cubiçoso", "Cobiçoso", 0) /* linha 2171 */
R(R_INTEIRA, "feril-os-á", "feri-los-á", 0) /* linha 2172 */
R(R_INTEIRA, "Feril-os-á", "Feri-los-á", 0) /* linha 2173 */
R(R_INTEIRA, "podêssemos", "pudéssemos", 0) /* linha 2174 */
R(R_INTEIRA, "Podêssemos", "Pudéssemos", 0) /* linha 2175 */
R(R_INTEIRA, "anuncíeis", "anuncieis", 0) /* linha 2176 */
R(R_INTEIRA, "Anuncíeis", "Anuncieis", 0) /* linha 2177 */
R(R_INTEIRA, "caires", "caíres", 0) /* linha 2178 */
R(R_INTEIRA, "Caires", "Caíres", 0) /* linha 2179 */
R(R_INTEIRA, "diminuida", "diminuída", 0) /* linha 2180 */
R(R_INTEIRA, "Diminuida", "Diminuída", 0) /* linha 2181 */
R(R_INTEIRA, "podera", "pudera", 0) /* linha 2182 */
R(R_INTEIRA, "Podera", "Pudera", 0) /* linha 2183 */
R(R_INTEIRA, "orfãosinho", "orfãozinho", 0) /* linha 2184 */
R(R_INTEIRA, "Orfãosinho", "Orfãozinho", 0) /* linha 2185 */
R(R_INTEIRA, "sobreedificados", "sobre-edificados", 0) /* linha 2186 */
R(R_INTEIRA, "Sobreedificados", "Sobre-edificados", 0) /* linha 2187 */
R(R_INTEIRA, "pôres", "pores", 0) /* linha 2188 */
R(R_INTEIRA, "Pôres", "Pores", 0) /* linha 2189 */
R(R_INTEIRA, "diminuim", "diminuem", 0) /* linha 2190 */
R(R_INTEIRA, "Diminuim", "Diminuem", 0) /* linha 2191 */
R(R_INTEIRA, "purpurea", "purpúrea", 0) /* linha 2192 */
R(R_INTEIRA, "Purpurea", "Purpúrea", 0) /* linha 2193 */
R(R_INTEIRA, "exhortando", "exortando", 0) /* linha 2194 */
R(R_INTEIRA, "Exhortando", "Exortando", 0) /* linha 2195 */
R(R_INTEIRA, "enfastíeis", "enfastieis", 0) /* linha 2196 */
R(R_INTEIRA, "Enfastíeis", "Enfastieis", 0) /* linha 2197 */
R(R_INTEIRA, "detens", "deténs", 0) /* linha 2198 */
R(R_INTEIRA, "Detens", "Deténs", 0) /* linha 2199 */
R(R_INTEIRA, "quisereis", "quiserdes", 0) /* linha 2200 */
R(R_INTEIRA, "Quisereis", "Quiserdes", 0) /* linha 2201 */
R(R_INTEIRA, "desarreiguemô-la", "desarraiguemo-la", 0) /* linha 2202 */
R(R_INTEIRA, "Desarreiguemô-la", "Desarraiguemo-la", 0) /* linha 2203 */
R(R_INTEIRA, "noticíeis", "noticieis", 0) /* linha 2204 */
R(R_INTEIRA, "Noticíeis", "Noticieis", 0) /* linha 2205 */
R(R_INTEIRA, "destruimos", "destruímos", 0) /* linha 2206 */
R(R_INTEIRA, "Destruimos", "Destruímos", 0) /* linha 2207 */
R(R_INTEIRA, "destrui-a", "destruí-a", 0) /* linha 2208 */
R(R_INTEIRA, "Destrui-a", "Destruí-a", 0) /* linha 2209 */
R(R_INTEIRA, "impôz", "impôs", 0) /* linha 2210 */
R(R_INTEIRA, "Impôz", "Impôs", 0) /* linha 2211 */
R(R_INTEIRA, "desviemô-los", "desviemo-los", 0) /* linha 2212 */
R(R_INTEIRA, "Desviemô-los", "Desviemo-los", 0) /* linha 2213 */
R(R_INTEIRA, "adheriu", "aderiu", 0) /* linha 2214 */
R(R_INTEIRA, "Adheriu", "Aderiu", 0) /* linha 2215 */
R(R_INTEIRA, "posaam", "possam", 0) /* linha 2216 */
R(R_INTEIRA, "Posaam", "Possam", 0) /* linha 2217 */
R(R_INTEIRA, "ateem", "atêm", 0) /* linha 2218 */
R(R_INTEIRA, "Ateem", "Atêm", 0) /* linha 2219 */
R(R_INTEIRA, "reverenceie", "reverencie", 0) /* linha 2220 */
R(R_INTEIRA, "Reverenceie", "Reverencie", 0) /* linha 2221 */
R(R_INTEIRA, "passeam", "passeiam", 0) /* linha 2222 */
R(R_INTEIRA, "Passeam", "Passeiam", 0) /* linha 2223 */
R(R_INTEIRA, "jurámos-lhes", "juramos-lhes", 0) /* linha 2224 */
R(R_INTEIRA, "Jurámos-lhes", "Juramos-lhes", 0) /* linha 2225 */
R(R_INTEIRA, "rogozijando-se", "regozijando-se", 0) /* linha 2226 */
R(R_INTEIRA, "Rogozijando-se", "Regozijando-se", 0) /* linha 2227 */
R(R_INTEIRA, "concluida", "concluída", 0) /* linha 2228 */
R(R_INTEIRA, "Concluida", "Concluída", 0) /* linha 2229 */
R(R_INTEIRA, "practicai", "praticai", 0) /* linha 2230 */
R(R_INTEIRA, "Practicai", "Praticai", 0) /* linha 2231 */
R(R_INTEIRA, "negoceia", "negocia", 0) /* linha 2232 */
R(R_INTEIRA, "Negoceia", "Negocia", 0) /* linha 2233 */
R(R_INTEIRA, "lagôas", "lagoas", 0) /* linha 2234 */
R(R_INTEIRA, "Lagôas", "Lagoas", 0) /* linha 2235 */
R(R_INTEIRA, "vendamô-lo", "vendamo-lo", 0) /* linha 2236 */
R(R_INTEIRA, "Vendamô-lo", "Vendamo-lo", 0) /* linha 2237 */
R(R_INTEIRA, "destruimô-las", "destruímo-las", 0) /* linha 2238 */
R(R_INTEIRA, "Destruimô-las", "Destruímo-las", 0) /* linha 2239 */
R(R_INTEIRA, "cordealmente", "cordialmente", 0) /* linha 2240 */
R(R_INTEIRA, "Cordealmente", "Cordialmente", 0) /* linha 2241 */
R(R_INTEIRA, "praticos", "práticos", 0) /* linha 2242 */
R(R_INTEIRA, "Praticos", "Práticos", 0) /* linha 2243 */
R(R_INTEIRA, "aflictíssimo", "aflitíssimo", 0) /* linha 2244 */
R(R_INTEIRA, "Aflictíssimo", "Aflitíssimo", 0) /* linha 2245 */
R(R_INTEIRA, "prostituiram", "prostituíram", 0) /* linha 2246 */
R(R_INTEIRA, "Prostituiram", "Prostituíram", 0) /* linha 2247 */
R(R_INTEIRA, "deshonestidades", "desonestidades", 0) /* linha 2248 */
R(R_INTEIRA, "Deshonestidades", "Desonestidades", 0) /* linha 2249 */
R(R_INTEIRA, "multiplice", "múltiplice", 0) /* linha 2250 */
R(R_INTEIRA, "Multiplice", "Múltiplice", 0) /* linha 2251 */
R(R_INTEIRA, "investiguemô-los", "investiguemo-los", 0) /* linha 2252 */
R(R_INTEIRA, "Investiguemô-los", "Investiguemo-los", 0) /* linha 2253 */
R(R_INTEIRA, "heteas", "heteias", 0) /* linha 2254 */
R(R_INTEIRA, "Heteas", "Heteias", 0) /* linha 2255 */
R(R_INTEIRA, "incircumcisa", "incircuncisa", 0) /* linha 2256 */
R(R_INTEIRA, "Incircumcisa", "Incircuncisa", 0) /* linha 2257 */
R(R_INTEIRA, "odorifera", "odorífera", 0) /* linha 2258 */
R(R_INTEIRA, "Odorifera", "Odorífera", 0) /* linha 2259 */
R(R_INTEIRA, "aligera", "alígera", 0) /* linha 2260 */
R(R_INTEIRA, "Aligera", "Alígera", 0) /* linha 2261 */
R(R_INTEIRA, "efectuarás", "efetuarás", 0) /* linha 2262 */
R(R_INTEIRA, "Efectuarás", "Efetuarás", 0) /* linha 2263 */
R(R_INTEIRA, "triumfou", "triunfou", 0) /* linha 2264 */
R(R_INTEIRA, "Triumfou", "Triunfou", 0) /* linha 2265 */
R(R_INTEIRA, "contentaramos", "contentáramos", 0) /* linha 2266 */
R(R_INTEIRA, "Contentaramos", "Contentáramos", 0) /* linha 2267 */
R(R_INTEIRA, "levéda", "leveda", 0) /* linha 2268 */
R(R_INTEIRA, "Levéda", "Leveda", 0) /* linha 2269 */
R(R_INTEIRA, "deprezo", "desprezo", 0) /* linha 2270 */
R(R_INTEIRA, "Deprezo", "Desprezo", 0) /* linha 2271 */
R(R_INTEIRA, "grangear", "granjear", 0) /* linha 2272 */
R(R_INTEIRA, "Grangear", "Granjear", 0) /* linha 2273 */
R(R_INTEIRA, "triumfem", "triunfem", 0) /* linha 2274 */
R(R_INTEIRA, "Triumfem", "Triunfem", 0) /* linha 2275 */
R(R_INTEIRA, "afectos", "afetos", 0) /* linha 2276 */
R(R_INTEIRA, "Afectos", "Afetos", 0) /* linha 2277 */
R(R_INTEIRA, "inprecações", "imprecações", 0) /* linha 2278 */
R(R_INTEIRA, "Inprecações", "Imprecações", 0) /* linha 2279 */
R(R_INTEIRA, "visseis", "vísseis", 0) /* linha 2280 */
R(R_INTEIRA, "Visseis", "Vísseis", 0) /* linha 2281 */
R(R_INTEIRA, "constituistes", "constituístes", 0) /* linha 2282 */
R(R_INTEIRA, "Constituistes", "Constituístes", 0) /* linha 2283 */
R(R_INTEIRA, "possuistes", "possuístes", 0) /* linha 2284 */
R(R_INTEIRA, "Possuistes", "Possuístes", 0) /* linha 2285 */
R(R_INTEIRA, "cubiçar", "cobiçar", 0) /* linha 2286 */
R(R_INTEIRA, "Cubiçar", "Cobiçar", 0) /* linha 2287 */
R(R_INTEIRA, "distribuia", "distribuía", 0) /* linha 2288 */
R(R_INTEIRA, "Distribuia", "Distribuía", 0) /* linha 2289 */
R(R_INTEIRA, "opéro", "opero", 0) /* linha 2290 */
R(R_INTEIRA, "Opéro", "Opero", 0) /* linha 2291 */
R(R_INTEIRA, "dáes", "dais", 0) /* linha 2292 */
R(R_INTEIRA, "Dáes", "Dais", 0) /* linha 2293 */
R(R_INTEIRA, "proseguiremos", "prosseguiremos", 0) /* linha 2294 */
R(R_INTEIRA, "Proseguiremos", "Prosseguiremos", 0) /* linha 2295 */
R(R_INTEIRA, "perseguil-os-hei", "persegui-los-ei", 0) /* linha 2296 */
R(R_INTEIRA, "Perseguil-os-hei", "Persegui-los-ei", 0) /* linha 2297 */
R(R_INTEIRA, "sobresalte", "sobressalte", 0) /* linha 2298 */
R(R_INTEIRA, "Sobresalte", "Sobressalte", 0) /* linha 2299 */
R(R_INTEIRA, "excluida", "excluída", 0) /* linha 2300 */
R(R_INTEIRA, "Excluida", "Excluída", 0) /* linha 2301 */
R(R_INTEIRA, "géra", "gera", 0) /* linha 2302 */
R(R_INTEIRA, "Géra", "Gera", 0) /* linha 2303 */
R(R_INTEIRA, "confeção", "confecção", 0) /* linha 2304 */
R(R_INTEIRA, "Confeção", "Confecção", 0) /* linha 2305 */
R(R_INTEIRA, "exhorto-vos", "exorto-vos", 0) /* linha 2306 */
R(R_INTEIRA, "Exhorto-vos", "Exorto-vos", 0) /* linha 2307 */
R(R_INTEIRA, "susteem", "sustêm", 0) /* linha 2308 */
R(R_INTEIRA, "Susteem", "Sustêm", 0) /* linha 2309 */
R(R_INTEIRA, "efectuará", "efetuará", 0) /* linha 2310 */
R(R_INTEIRA, "Efectuará", "Efetuará", 0) /* linha 2311 */
R(R_INTEIRA, "grangeiam", "granjeiam", 0) /* linha 2312 */
R(R_INTEIRA, "Grangeiam", "Granjeiam", 0) /* linha 2313 */
R(R_INTEIRA, "siro-fenicia", "siro-fenícia", 0) /* linha 2314 */
R(R_INTEIRA, "Siro-fenicia", "Siro-fenícia", 0) /* linha 2315 */
R(R_INTEIRA, "cortemô-lo", "cortemo-lo", 0) /* linha 2316 */
R(R_INTEIRA, "Cortemô-lo", "Cortemo-lo", 0) /* linha 2317 */
R(R_INTEIRA, "virámo-nos", "viramo-nos", 0) /* linha 2318 */
R(R_INTEIRA, "Virámo-nos", "Viramo-nos", 0) /* linha 2319 */
R(R_INTEIRA, "vasarei", "vazarei", 0) /* linha 2320 */
R(R_INTEIRA, "Vasarei", "Vazarei", 0) /* linha 2321 */
R(R_INTEIRA, "rez", "rês", 0) /* linha 2322 */
R(R_INTEIRA, "Rez", "Rês", 0) /* linha 2323 */
R(R_INTEIRA, "reflectindo", "refletindo", 0) /* linha 2324 */
R(R_INTEIRA, "Reflectindo", "Refletindo", 0) /* linha 2325 */
R(R_INTEIRA, "exhortaram", "exortaram", 0) /* linha 2326 */
R(R_INTEIRA, "Exhortaram", "Exortaram", 0) /* linha 2327 */
R(R_INTEIRA, "sirvamô-los", "sirvamo-los", 0) /* linha 2328 */
R(R_INTEIRA, "Sirvamô-los", "Sirvamo-los", 0) /* linha 2329 */
R(R_INTEIRA, "proconsules", "procônsules", 0) /* linha 2330 */
R(R_INTEIRA, "Proconsules", "Procônsules", 0) /* linha 2331 */
R(R_INTEIRA, "sirios", "sírios", 0) /* linha 2332 */
R(R_INTEIRA, "Sirios", "Sírios", 0) /* linha 2333 */
R(R_INTEIRA, "possuiam", "possuíam", 0) /* linha 2334 */
R(R_INTEIRA, "Possuiam", "Possuíam", 0) /* linha 2335 */
R(R_INTEIRA, "pôe-no", "põe-no", 0) /* linha 2336 */
R(R_INTEIRA, "Pôe-no", "Põe-no", 0) /* linha 2337 */
R(R_INTEIRA, "desd'as", "desde as", 0) /* linha 2338 */
R(R_INTEIRA, "Desd'as", "Desde as", 0) /* linha 2339 */
R(R_INTEIRA, "bemfeitores", "benfeitores", 0) /* linha 2340 */
R(R_INTEIRA, "Bemfeitores", "Benfeitores", 0) /* linha 2341 */
R(R_INTEIRA, "cairam-lhe", "caíram-lhe", 0) /* linha 2342 */
R(R_INTEIRA, "Cairam-lhe", "Caíram-lhe", 0) /* linha 2343 */
R(R_INTEIRA, "varôa", "varoa", 0) /* linha 2344 */
R(R_INTEIRA, "Varôa", "Varoa", 0) /* linha 2345 */
R(R_INTEIRA, "sára", "sara", 0) /* linha 2346 */
R(R_INTEIRA, "Sára", "Sara", 0) /* linha 2347 */
R(R_INTEIRA, "esbofetéar", "esbofetear", 0) /* linha 2348 */
R(R_INTEIRA, "Esbofetéar", "Esbofetear", 0) /* linha 2349 */
R(R_INTEIRA, "odorifero", "odorífero", 0) /* linha 2350 */
R(R_INTEIRA, "Odorifero", "Odorífero", 0) /* linha 2351 */
R(R_INTEIRA, "siriaca", "siríaca", 0) /* linha 2352 */
R(R_INTEIRA, "Siriaca", "Siríaca", 0) /* linha 2353 */
R(R_INTEIRA, "ameacemô-los", "ameacemo-los", 0) /* linha 2354 */
R(R_INTEIRA, "Ameacemô-los", "Ameacemo-los", 0) /* linha 2355 */
R(R_INTEIRA, "ornatorias", "ornatórias", 0) /* linha 2356 */
R(R_INTEIRA, "Ornatorias", "Ornatórias", 0) /* linha 2357 */
R(R_INTEIRA, "presbiterio", "presbitério", 0) /* linha 2358 */
R(R_INTEIRA, "Presbiterio", "Presbitério", 0) /* linha 2359 */
R(R_INTEIRA, "sobreveiu-lhes", "sobreveio-lhes", 0) /* linha 2360 */
R(R_INTEIRA, "Sobreveiu-lhes", "Sobreveio-lhes", 0) /* linha 2361 */
R(R_INTEIRA, "destruisses", "destruísses", 0) /* linha 2362 */
R(R_INTEIRA, "Destruisses", "Destruísses", 0) /* linha 2363 */
R(R_INTEIRA, "apanhal-os-á", "apanhá-los-á", 0) /* linha 2364 */
R(R_INTEIRA, "Apanhal-os-á", "Apanhá-los-á", 0) /* linha 2365 */
R(R_INTEIRA, "decaiste", "decaíste", 0) /* linha 2366 */
R(R_INTEIRA, "Decaiste", "Decaíste", 0) /* linha 2367 */
R(R_INTEIRA, "deter-vos-híeis", "deter-vos-íeis", 0) /* linha 2368 */
R(R_INTEIRA, "Deter-vos-híeis", "Deter-vos-íeis", 0) /* linha 2369 */
R(R_INTEIRA, "rogámos-lhe", "rogamos-lhe", 0) /* linha 2370 */
R(R_INTEIRA, "Rogámos-lhe", "Rogamos-lhe", 0) /* linha 2371 */
R(R_INTEIRA, "conveiu", "conveio", 0) /* linha 2372 */
R(R_INTEIRA, "Conveiu", "Conveio", 0) /* linha 2373 */
R(R_INTEIRA, "sitía", "sitia", 0) /* linha 2374 */
R(R_INTEIRA, "Sitía", "Sitia", 0) /* linha 2375 */
R(R_INTEIRA, "distribuiam", "distribuíam", 0) /* linha 2376 */
R(R_INTEIRA, "Distribuiam", "Distribuíam", 0) /* linha 2377 */
R(R_INTEIRA, "possuissem", "possuíssem", 0) /* linha 2378 */
R(R_INTEIRA, "Possuissem", "Possuíssem", 0) /* linha 2379 */
R(R_INTEIRA, "ferteis", "férteis", 0) /* linha 2380 */
R(R_INTEIRA, "Ferteis", "Férteis", 0) /* linha 2381 */
R(R_INTEIRA, "condiscipulos", "condiscípulos", 0) /* linha 2382 */
R(R_INTEIRA, "Condiscipulos", "Condiscípulos", 0) /* linha 2383 */
R(R_INTEIRA, "sobria", "sóbria", 0) /* linha 2384 */
R(R_INTEIRA, "Sobria", "Sóbria", 0) /* linha 2385 */
R(R_INTEIRA, "passea", "passeia", 0) /* linha 2386 */
R(R_INTEIRA, "Passea", "Passeia", 0) /* linha 2387 */
R(R_INTEIRA, "incircumcidado", "incircunciso", 0) /* linha 2388 */
R(R_INTEIRA, "Incircumcidado", "Incircunciso", 0) /* linha 2389 */
R(R_INTEIRA, "pôl-a-hei", "pô-la-ei", 0) /* linha 2390 */
R(R_INTEIRA, "Pôl-a-hei", "Pô-la-ei", 0) /* linha 2391 */
R(R_INTEIRA, "dir-vos-hão", "dir-vos-ão", 0) /* linha 2392 */
R(R_INTEIRA, "Dir-vos-hão", "Dir-vos-ão", 0) /* linha 2393 */
R(R_INTEIRA, "proseguiram", "prosseguiram", 0) /* linha 2394 */
R(R_INTEIRA, "Proseguiram", "Prosseguiram", 0) /* linha 2395 */
R(R_INTEIRA, "voltar-mos", "voltarmos", 0) /* linha 2396 */
R(R_INTEIRA, "Voltar-mos", "Voltarmos", 0) /* linha 2397 */
R(R_INTEIRA, "sobresaltada", "sobressaltada", 0) /* linha 2398 */
R(R_INTEIRA, "Sobresaltada", "Sobressaltada", 0) /* linha 2399 */
R(R_INTEIRA, "pôl-os-hei", "pô-los-ei", 0) /* linha 2400 */
R(R_INTEIRA, "Pôl-os-hei", "Pô-los-ei", 0) /* linha 2401 */
R(R_INTEIRA, "deshonras", "desonras", 0) /* linha 2402 */
R(R_INTEIRA, "Deshonras", "Desonras", 0) /* linha 2403 */
R(R_INTEIRA, "vasou", "vazou", 0) /* linha 2404 */
R(R_INTEIRA, "Vasou", "Vazou", 0) /* linha 2405 */
R(R_INTEIRA, "afligil-os-hão", "afligi-los-ão", 0) /* linha 2406 */
R(R_INTEIRA, "Afligil-os-hão", "Afligi-los-ão", 0) /* linha 2407 */
R(R_INTEIRA, "ten", "teu", 0) /* linha 2408 */
R(R_INTEIRA, "Ten", "Teu", 0) /* linha 2409 */
R(R_INTEIRA, "encurvande", "encurvando", 0) /* linha 2410 */
R(R_INTEIRA, "Encurvande", "Encurvando", 0) /* linha 2411 */
R(R_INTEIRA, "deshonrastes", "desonrastes", 0) /* linha 2412 */
R(R_INTEIRA, "Deshonrastes", "Desonrastes", 0) /* linha 2413 */
R(R_INTEIRA, "móra", "mora", 0) /* linha 2414 */
R(R_INTEIRA, "Móra", "Mora", 0) /* linha 2415 */
R(R_INTEIRA, "esperamô-lo", "esperamo-lo", 0) /* linha 2416 */
R(R_INTEIRA, "Esperamô-lo", "Esperamo-lo", 0) /* linha 2417 */
R(R_INTEIRA, "caissem", "caíssem", 0) /* linha 2418 */
R(R_INTEIRA, "Caissem", "Caíssem", 0) /* linha 2419 */
R(R_INTEIRA, "descahiam", "descaíam", 0) /* linha 2420 */
R(R_INTEIRA, "Descahiam", "Descaíam", 0) /* linha 2421 */
R(R_INTEIRA, "médo", "medo", 0) /* linha 2422 */
R(R_INTEIRA, "Médo", "Medo", 0) /* linha 2423 */
R(R_INTEIRA, "choviscos", "chuviscos", 0) /* linha 2424 */
R(R_INTEIRA, "Choviscos", "Chuviscos", 0) /* linha 2425 */
R(R_INTEIRA, "vasaste", "vazaste", 0) /* linha 2426 */
R(R_INTEIRA, "Vasaste", "Vazaste", 0) /* linha 2427 */
R(R_INTEIRA, "crêsse", "cresse", 0) /* linha 2428 */
R(R_INTEIRA, "Crêsse", "Cresse", 0) /* linha 2429 */
R(R_INTEIRA, "avisinhará", "avizinhará", 0) /* linha 2430 */
R(R_INTEIRA, "Avisinhará", "Avizinhará", 0) /* linha 2431 */
R(R_INTEIRA, "enviemô-los", "enviemo-los", 0) /* linha 2432 */
R(R_INTEIRA, "Enviemô-los", "Enviemo-los", 0) /* linha 2433 */
R(R_INTEIRA, "dalem", "além", 0) /* linha 2434 */
R(R_INTEIRA, "Dalem", "Além", 0) /* linha 2435 */
R(R_INTEIRA, "cubiçastes", "cobiçastes", 0) /* linha 2436 */
R(R_INTEIRA, "Cubiçastes", "Cobiçastes", 0) /* linha 2437 */
R(R_INTEIRA, "confortadgos", "confortados", 0) /* linha 2438 */
R(R_INTEIRA, "Confortadgos", "Confortados", 0) /* linha 2439 */
R(R_INTEIRA, "frecháda", "flechada", 0) /* linha 2440 */
R(R_INTEIRA, "Frecháda", "Flechada", 0) /* linha 2441 */
R(R_INTEIRA, "convezes", "conveses", 0) /* linha 2442 */
R(R_INTEIRA, "Convezes", "Conveses", 0) /* linha 2443 */
R(R_INTEIRA, "aformosea", "aformoseia", 0) /* linha 2444 */
R(R_INTEIRA, "Aformosea", "Aformoseia", 0) /* linha 2445 */
R(R_INTEIRA, "chronista", "cronista", 0) /* linha 2446 */
R(R_INTEIRA, "Chronista", "Cronista", 0) /* linha 2447 */
R(R_INTEIRA, "sobresahia", "sobressaía", 0) /* linha 2448 */
R(R_INTEIRA, "Sobresahia", "Sobressaía", 0) /* linha 2449 */
R(R_INTEIRA, "prohibido", "proibido", 0) /* linha 2450 */
R(R_INTEIRA, "Prohibido", "Proibido", 0) /* linha 2451 */
R(R_INTEIRA, "prosigamos", "prossigamos", 0) /* linha 2452 */
R(R_INTEIRA, "Prosigamos", "Prossigamos", 0) /* linha 2453 */
R(R_INTEIRA, "dir-lhe-hei", "dir-lhe-ei", 0) /* linha 2454 */
R(R_INTEIRA, "Dir-lhe-hei", "Dir-lhe-ei", 0) /* linha 2455 */
R(R_INTEIRA, "prohibia", "proibia", 0) /* linha 2456 */
R(R_INTEIRA, "Prohibia", "Proibia", 0) /* linha 2457 */
R(R_INTEIRA, "curuja", "coruja", 0) /* linha 2458 */
R(R_INTEIRA, "Curuja", "Coruja", 0) /* linha 2459 */
R(R_INTEIRA, "dictava-me", "ditava-me", 0) /* linha 2460 */
R(R_INTEIRA, "Dictava-me", "Ditava-me", 0) /* linha 2461 */
R(R_INTEIRA, "desposorios", "desposórios", 0) /* linha 2462 */
R(R_INTEIRA, "Desposorios", "Desposórios", 0) /* linha 2463 */
R(R_INTEIRA, "vol", "vo-lo", 0) /* linha 2464 */
R(R_INTEIRA, "Vol", "Vo-lo", 0) /* linha 2465 */
R(R_INTEIRA, "reflectirás", "refletirás", 0) /* linha 2466 */
R(R_INTEIRA, "Reflectirás", "Refletirás", 0) /* linha 2467 */
R(R_INTEIRA, "assenhoream", "assenhoreiam", 0) /* linha 2468 */
R(R_INTEIRA, "Assenhoream", "Assenhoreiam", 0) /* linha 2469 */
R(R_INTEIRA, "contámos-lhos", "contamos-lhos", 0) /* linha 2470 */
R(R_INTEIRA, "Contámos-lhos", "Contamos-lhos", 0) /* linha 2471 */
R(R_INTEIRA, "siriacos", "siríacos", 0) /* linha 2472 */
R(R_INTEIRA, "Siriacos", "Siríacos", 0) /* linha 2473 */
R(R_INTEIRA, "cerquemô-las", "cerquemo-las", 0) /* linha 2474 */
R(R_INTEIRA, "Cerquemô-las", "Cerquemo-las", 0) /* linha 2475 */
R(R_INTEIRA, "efectuados", "efetuados", 0) /* linha 2476 */
R(R_INTEIRA, "Efectuados", "Efetuados", 0) /* linha 2477 */
R(R_INTEIRA, "contradicto", "contradito", 0) /* linha 2478 */
R(R_INTEIRA, "Contradicto", "Contradito", 0) /* linha 2479 */
R(R_INTEIRA, "expuz-lhe", "expus-lhe", 0) /* linha 2480 */
R(R_INTEIRA, "Expuz-lhe", "Expus-lhe", 0) /* linha 2481 */
R(R_INTEIRA, "disséra", "dissera", 0) /* linha 2482 */
R(R_INTEIRA, "Disséra", "Dissera", 0) /* linha 2483 */
R(R_INTEIRA, "circunvisinhos", "circunvizinhos", 0) /* linha 2484 */
R(R_INTEIRA, "Circunvisinhos", "Circunvizinhos", 0) /* linha 2485 */
R(R_INTEIRA, "arduo", "árduo", 0) /* linha 2486 */
R(R_INTEIRA, "Arduo", "Árduo", 0) /* linha 2487 */
R(R_INTEIRA, "licaonica", "licaônica", 0) /* linha 2488 */
R(R_INTEIRA, "Licaonica", "Licaônica", 0) /* linha 2489 */
R(R_INTEIRA, "infrutiferas", "infrutíferas", 0) /* linha 2490 */
R(R_INTEIRA, "Infrutiferas", "Infrutíferas", 0) /* linha 2491 */
R(R_INTEIRA, "receiou", "receou", 0) /* linha 2492 */
R(R_INTEIRA, "Receiou", "Receou", 0) /* linha 2493 */
R(R_INTEIRA, "tomámô-lo", "tomamo-lo", 0) /* linha 2494 */
R(R_INTEIRA, "Tomámô-lo", "Tomamo-lo", 0) /* linha 2495 */
R(R_INTEIRA, "desposorio", "desposório", 0) /* linha 2496 */
R(R_INTEIRA, "Desposorio", "Desposório", 0) /* linha 2497 */
R(R_INTEIRA, "aflictiva", "aflitiva", 0) /* linha 2498 */
R(R_INTEIRA, "Aflictiva", "Aflitiva", 0) /* linha 2499 */
R(R_INTEIRA, "refrea", "refreia", 0) /* linha 2500 */
R(R_INTEIRA, "Refrea", "Refreia", 0) /* linha 2501 */
R(R_INTEIRA, "pol-o-hão", "pô-lo-ão", 0) /* linha 2502 */
R(R_INTEIRA, "Pol-o-hão", "Pô-lo-ão", 0) /* linha 2503 */
R(R_INTEIRA, "possuiste", "possuíste", 0) /* linha 2504 */
R(R_INTEIRA, "Possuiste", "Possuíste", 0) /* linha 2505 */
R(R_INTEIRA, "dromedaria", "dromedária", 0) /* linha 2506 */
R(R_INTEIRA, "Dromedaria", "Dromedária", 0) /* linha 2507 */
R(R_INTEIRA, "dir-te-hão", "dir-te-ão", 0) /* linha 2508 */
R(R_INTEIRA, "Dir-te-hão", "Dir-te-ão", 0) /* linha 2509 */
R(R_INTEIRA, "cohabitai", "coabitai", 0) /* linha 2510 */
R(R_INTEIRA, "Cohabitai", "Coabitai", 0) /* linha 2511 */
R(R_INTEIRA, "concluiam", "concluíam", 0) /* linha 2512 */
R(R_INTEIRA, "Concluiam", "Concluíam", 0) /* linha 2513 */
R(R_INTEIRA, "resicados", "ressecados", 0) /* linha 2514 */
R(R_INTEIRA, "Resicados", "Ressecados", 0) /* linha 2515 */
R(R_INTEIRA, "dizéndo", "dizendo", 0) /* linha 2516 */
R(R_INTEIRA, "Dizéndo", "Dizendo", 0) /* linha 2517 */
R(R_INTEIRA, "decairem", "decaírem", 0) /* linha 2518 */
R(R_INTEIRA, "Decairem", "Decaírem", 0) /* linha 2519 */
R(R_INTEIRA, "habitalas", "habitá-las", 0) /* linha 2520 */
R(R_INTEIRA, "Habitalas", "Habitá-las", 0) /* linha 2521 */
R(R_INTEIRA, "opoz", "opôs", 0) /* linha 2522 */
R(R_INTEIRA, "Opoz", "Opôs", 0) /* linha 2523 */
R(R_INTEIRA, "galatas", "gálatas", 0) /* linha 2524 */
R(R_INTEIRA, "Galatas", "Gálatas", 0) /* linha 2525 */
R(R_INTEIRA, "porteiros-móres", "porteiros-mores", 0) /* linha 2526 */
R(R_INTEIRA, "Porteiros-móres", "Porteiros-mores", 0) /* linha 2527 */
R(R_INTEIRA, "est'", "estas", 0) /* linha 2528 */
R(R_INTEIRA, "Est'", "Estas", 0) /* linha 2529 */
R(R_INTEIRA, "echo", "eco", 0) /* linha 2530 */
R(R_INTEIRA, "Echo", "Eco", 0) /* linha 2531 */
R(R_INTEIRA, "médos", "medos", 0) /* linha 2532 */
R(R_INTEIRA, "Médos", "Medos", 0) /* linha 2533 */
R(R_INTEIRA, "quaesquer", "quaisquer", 0) /* linha 2534 */
R(R_INTEIRA, "Quaesquer", "Quaisquer", 0) /* linha 2535 */
R(R_INTEIRA, "prostituiste", "prostituíste", 0) /* linha 2536 */
R(R_INTEIRA, "Prostituiste", "Prostituíste", 0) /* linha 2537 */
R(R_INTEIRA, "destituidos", "destituídos", 0) /* linha 2538 */
R(R_INTEIRA, "Destituidos", "Destituídos", 0) /* linha 2539 */
R(R_INTEIRA, "abroga-se", "ab-roga-se", 0) /* linha 2540 */
R(R_INTEIRA, "Abroga-se", "Ab-roga-se", 0) /* linha 2541 */
R(R_INTEIRA, "directamente", "diretamente", 0) /* linha 2542 */
R(R_INTEIRA, "Directamente", "Diretamente", 0) /* linha 2543 */
R(R_INTEIRA, "cohibiram", "coibiram", 0) /* linha 2544 */
R(R_INTEIRA, "Cohibiram", "Coibiram", 0) /* linha 2545 */
R(R_INTEIRA, "vasaram", "vazaram", 0) /* linha 2546 */
R(R_INTEIRA, "Vasaram", "Vazaram", 0) /* linha 2547 */
R(R_INTEIRA, "prohibisse", "proibisse", 0) /* linha 2548 */
R(R_INTEIRA, "Prohibisse", "Proibisse", 0) /* linha 2549 */
R(R_INTEIRA, "exhortes", "exortes", 0) /* linha 2550 */
R(R_INTEIRA, "Exhortes", "Exortes", 0) /* linha 2551 */
R(R_INTEIRA, "sobreveiu-lhe", "sobreveio-lhe", 0) /* linha 2552 */
R(R_INTEIRA, "Sobreveiu-lhe", "Sobreveio-lhe", 0) /* linha 2553 */
R(R_INTEIRA, "sobresair", "sobressair", 0) /* linha 2554 */
R(R_INTEIRA, "Sobresair", "Sobressair", 0) /* linha 2555 */
R(R_INTEIRA, "recaisse", "recaísse", 0) /* linha 2556 */
R(R_INTEIRA, "Recaisse", "Recaísse", 0) /* linha 2557 */
R(R_INTEIRA, "deshonrada", "desonrada", 0) /* linha 2558 */
R(R_INTEIRA, "Deshonrada", "Desonrada", 0) /* linha 2559 */
R(R_INTEIRA, "babilonica", "babilônica", 0) /* linha 2560 */
R(R_INTEIRA, "Babilonica", "Babilônica", 0) /* linha 2561 */
R(R_INTEIRA, "levitico", "levítico", 0) /* linha 2562 */
R(R_INTEIRA, "Levitico", "Levítico", 0) /* linha 2563 */
R(R_INTEIRA, "pósinhos", "pozinhos", 0) /* linha 2564 */
R(R_INTEIRA, "Pósinhos", "Pozinhos", 0) /* linha 2565 */
R(R_INTEIRA, "comerãs", "comerás", 0) /* linha 2566 */
R(R_INTEIRA, "Comerãs", "Comerás", 0) /* linha 2567 */
R(R_INTEIRA, "mesuros", "mesmos", 0) /* linha 2568 */
R(R_INTEIRA, "Mesuros", "Mesmos", 0) /* linha 2569 */
R(R_INTEIRA, "triumfo", "triunfo", 0) /* linha 2570 */
R(R_INTEIRA, "Triumfo", "Triunfo", 0) /* linha 2571 */
R(R_INTEIRA, "caimos", "caímos", 0) /* linha 2572 */
R(R_INTEIRA, "Caimos", "Caímos", 0) /* linha 2573 */
R(R_INTEIRA, "efectuado", "efetuado", 0) /* linha 2574 */
R(R_INTEIRA, "Efectuado", "Efetuado", 0) /* linha 2575 */
R(R_INTEIRA, "reconcilíeis", "reconcilieis", 0) /* linha 2576 */
R(R_INTEIRA, "Reconcilíeis", "Reconcilieis", 0) /* linha 2577 */
R(R_INTEIRA, "buscámô-lo", "buscamo-lo", 0) /* linha 2578 */
R(R_INTEIRA, "Buscámô-lo", "Buscamo-lo", 0) /* linha 2579 */
R(R_INTEIRA, "deshonrais", "desonrais", 0) /* linha 2580 */
R(R_INTEIRA, "Deshonrais", "Desonrais", 0) /* linha 2581 */
R(R_INTEIRA, "filacterias", "filactérias", 0) /* linha 2582 */
R(R_INTEIRA, "Filacterias", "Filactérias", 0) /* linha 2583 */
R(R_INTEIRA, "despedeçarei", "despedaçarei", 0) /* linha 2584 */
R(R_INTEIRA, "Despedeçarei", "Despedaçarei", 0) /* linha 2585 */
R(R_INTEIRA, "macãs", "maçãs", 0) /* linha 2586 */
R(R_INTEIRA, "Macãs", "Maçãs", 0) /* linha 2587 */
R(R_INTEIRA, "prohibe-lho", "proíbe-lho", 0) /* linha 2588 */
R(R_INTEIRA, "Prohibe-lho", "Proíbe-lho", 0) /* linha 2589 */
R(R_INTEIRA, "saisses", "saísses", 0) /* linha 2590 */
R(R_INTEIRA, "Saisses", "Saísses", 0) /* linha 2591 */
R(R_INTEIRA, "desarreiguemô-los", "desarraiguemo-los", 0) /* linha 2592 */
R(R_INTEIRA, "Desarreiguemô-los", "Desarraiguemo-los", 0) /* linha 2593 */
R(R_INTEIRA, "abenção", "bênção", 0) /* linha 2594 */
R(R_INTEIRA, "Abenção", "Bênção", 0) /* linha 2595 */
R(R_INTEIRA, "reunam", "reúnam", 0) /* linha 2596 */
R(R_INTEIRA, "Reunam", "Reúnam", 0) /* linha 2597 */
R(R_INTEIRA, "adheriam", "aderiam", 0) /* linha 2598 */
R(R_INTEIRA, "Adheriam", "Aderiam", 0) /* linha 2599 */
R(R_INTEIRA, "diabolica", "diabólica", 0) /* linha 2600 */
R(R_INTEIRA, "Diabolica", "Diabólica", 0) /* linha 2601 */
R(R_INTEIRA, "assentaram-ce", "assentaram-se", 0) /* linha 2602 */
R(R_INTEIRA, "Assentaram-ce", "Assentaram-se", 0) /* linha 2603 */
R(R_INTEIRA, "expuz", "expus", 0) /* linha 2604 */
R(R_INTEIRA, "Expuz", "Expus", 0) /* linha 2605 */
R(R_INTEIRA, "comissarios", "comissários", 0) /* linha 2606 */
R(R_INTEIRA, "Comissarios", "Comissários", 0) /* linha 2607 */
R(R_INTEIRA, "abstem", "abstêm", 0) /* linha 2608 */
R(R_INTEIRA, "Abstem", "Abstêm", 0) /* linha 2609 */
R(R_INTEIRA, "manuseis", "manuseies", 0) /* linha 2610 */
R(R_INTEIRA, "Manuseis", "Manuseies", 0) /* linha 2611 */
R(R_INTEIRA, "divídido", "dividido", 0) /* linha 2612 */
R(R_INTEIRA, "Divídido", "Dividido", 0) /* linha 2613 */
R(R_INTEIRA, "contrar", "contra", 0) /* linha 2614 */
R(R_INTEIRA, "Contrar", "Contra", 0) /* linha 2615 */
R(R_INTEIRA, "exhortavam", "exortavam", 0) /* linha 2616 */
R(R_INTEIRA, "Exhortavam", "Exortavam", 0) /* linha 2617 */
R(R_INTEIRA, "repartamô-lo", "repartamo-lo", 0) /* linha 2618 */
R(R_INTEIRA, "Repartamô-lo", "Repartamo-lo", 0) /* linha 2619 */
R(R_INTEIRA, "destruires", "destruíres", 0) /* linha 2620 */
R(R_INTEIRA, "Destruires", "Destruíres", 0) /* linha 2621 */
R(R_INTEIRA, "jubileo", "jubileu", 0) /* linha 2622 */
R(R_INTEIRA, "Jubileo", "Jubileu", 0) /* linha 2623 */
R(R_INTEIRA, "atribue", "atribui", 0) /* linha 2624 */
R(R_INTEIRA, "Atribue", "Atribui", 0) /* linha 2625 */
R(R_INTEIRA, "pranteam", "pranteiam", 0) /* linha 2626 */
R(R_INTEIRA, "Pranteam", "Pranteiam", 0) /* linha 2627 */
R(R_INTEIRA, "deshabitadas", "desabitadas", 0) /* linha 2628 */
R(R_INTEIRA, "Deshabitadas", "Desabitadas", 0) /* linha 2629 */
R(R_INTEIRA, "restituires", "restituíres", 0) /* linha 2630 */
R(R_INTEIRA, "Restituires", "Restituíres", 0) /* linha 2631 */
R(R_INTEIRA, "vomitalas-ha", "vomitá-las-á", 0) /* linha 2632 */
R(R_INTEIRA, "Vomitalas-ha", "Vomitá-las-á", 0) /* linha 2633 */
R(R_INTEIRA, "mármoreas", "marmóreas", 0) /* linha 2634 */
R(R_INTEIRA, "Mármoreas", "Marmóreas", 0) /* linha 2635 */
R(R_INTEIRA, "extinguí-la", "extingui-la", 0) /* linha 2636 */
R(R_INTEIRA, "Extinguí-la", "Extingui-la", 0) /* linha 2637 */
R(R_INTEIRA, "pôe-o", "põe-o", 0) /* linha 2638 */
R(R_INTEIRA, "Pôe-o", "Põe-o", 0) /* linha 2639 */
R(R_INTEIRA, "proveiu", "proveu", 0) /* linha 2640 */
R(R_INTEIRA, "Proveiu", "Proveu", 0) /* linha 2641 */
R(R_INTEIRA, "pôem", "põem", 0) /* linha 2642 */
R(R_INTEIRA, "Pôem", "Põem", 0) /* linha 2643 */
R(R_INTEIRA, "sacrilegos", "sacrílegos", 0) /* linha 2644 */
R(R_INTEIRA, "Sacrilegos", "Sacrílegos", 0) /* linha 2645 */
R(R_INTEIRA, "exhortando-o", "exortando-o", 0) /* linha 2646 */
R(R_INTEIRA, "Exhortando-o", "Exortando-o", 0) /* linha 2647 */
R(R_INTEIRA, "prohibiu", "proibiu", 0) /* linha 2648 */
R(R_INTEIRA, "Prohibiu", "Proibiu", 0) /* linha 2649 */
R(R_INTEIRA, "alimarias", "alimárias", 0) /* linha 2650 */
R(R_INTEIRA, "Alimarias", "Alimárias", 0) /* linha 2651 */
R(R_INTEIRA, "parvoices", "parvoíces", 0) /* linha 2652 */
R(R_INTEIRA, "Parvoices", "Parvoíces", 0) /* linha 2653 */
R(R_INTEIRA, "prohibira", "proibira", 0) /* linha 2654 */
R(R_INTEIRA, "Prohibira", "Proibira", 0) /* linha 2655 */
R(R_INTEIRA, "entaboladas", "entabuladas", 0) /* linha 2656 */
R(R_INTEIRA, "Entaboladas", "Entabuladas", 0) /* linha 2657 */
R(R_INTEIRA, "altisonantes", "altissonantes", 0) /* linha 2658 */
R(R_INTEIRA, "Altisonantes", "Altissonantes", 0) /* linha 2659 */
R(R_INTEIRA, "efectua", "efetua", 0) /* linha 2660 */
R(R_INTEIRA, "Efectua", "Efetua", 0) /* linha 2661 */
R(R_INTEIRA, "efectuo", "efetuo", 0) /* linha 2662 */
R(R_INTEIRA, "Efectuo", "Efetuo", 0) /* linha 2663 */
R(R_INTEIRA, "sobrias", "sóbrias", 0) /* linha 2664 */
R(R_INTEIRA, "Sobrias", "Sóbrias", 0) /* linha 2665 */
R(R_INTEIRA, "sofocam", "sufocam", 0) /* linha 2666 */
R(R_INTEIRA, "Sofocam", "Sufocam", 0) /* linha 2667 */
R(R_INTEIRA, "adoptou", "adotou", 0) /* linha 2668 */
R(R_INTEIRA, "Adoptou", "Adotou", 0) /* linha 2669 */
R(R_INTEIRA, "des-te", "deste", 0) /* linha 2670 */
R(R_INTEIRA, "Des-te", "Deste", 0) /* linha 2671 */
R(R_INTEIRA, "prohibe", "proíbe", 0) /* linha 2672 */
R(R_INTEIRA, "Prohibe", "Proíbe", 0) /* linha 2673 */
R(R_INTEIRA, "expôl-os-hão", "expô-los-ão", 0) /* linha 2674 */
R(R_INTEIRA, "Expôl-os-hão", "Expô-los-ão", 0) /* linha 2675 */
R(R_INTEIRA, "destrui-os", "destruí-os", 0) /* linha 2676 */
R(R_INTEIRA, "Destrui-os", "Destruí-os", 0) /* linha 2677 */
R(R_INTEIRA, "distribuisse", "distribuísse", 0) /* linha 2678 */
R(R_INTEIRA, "Distribuisse", "Distribuísse", 0) /* linha 2679 */
R(R_INTEIRA, "espadoas", "espáduas", 0) /* linha 2680 */
R(R_INTEIRA, "Espadoas", "Espáduas", 0) /* linha 2681 */
R(R_INTEIRA, "parvoice", "parvoíce", 0) /* linha 2682 */
R(R_INTEIRA, "Parvoice", "Parvoíce", 0) /* linha 2683 */
R(R_INTEIRA, "arripiado", "arrepiado", 0) /* linha 2684 */
R(R_INTEIRA, "Arripiado", "Arrepiado", 0) /* linha 2685 */
R(R_INTEIRA, "soborno", "suborno", 0) /* linha 2686 */
R(R_INTEIRA, "Soborno", "Suborno", 0) /* linha 2687 */
R(R_INTEIRA, "golosos", "gulosos", 0) /* linha 2688 */
R(R_INTEIRA, "Golosos", "Gulosos", 0) /* linha 2689 */
R(R_INTEIRA, "cedula", "cédula", 0) /* linha 2690 */
R(R_INTEIRA, "Cedula", "Cédula", 0) /* linha 2691 */
R(R_INTEIRA, "deshonestidade", "desonestidade", 0) /* linha 2692 */
R(R_INTEIRA, "Deshonestidade", "Desonestidade", 0) /* linha 2693 */
R(R_INTEIRA, "geracões", "gerações", 0) /* linha 2694 */
R(R_INTEIRA, "Geracões", "Gerações", 0) /* linha 2695 */
R(R_INTEIRA, "pêga", "pega", 0) /* linha 2696 */
R(R_INTEIRA, "Pêga", "Pega", 0) /* linha 2697 */
R(R_INTEIRA, "cubiçará", "cobiçará", 0) /* linha 2698 */
R(R_INTEIRA, "Cubiçará", "Cobiçará", 0) /* linha 2699 */
R(R_INTEIRA, "colirio", "colírio", 0) /* linha 2700 */
R(R_INTEIRA, "Colirio", "Colírio", 0) /* linha 2701 */
R(R_INTEIRA, "inhabitável", "inabitável", 0) /* linha 2702 */
R(R_INTEIRA, "Inhabitável", "Inabitável", 0) /* linha 2703 */
R(R_INTEIRA, "convência", "convencia", 0) /* linha 2704 */
R(R_INTEIRA, "Convência", "Convencia", 0) /* linha 2705 */
R(R_INTEIRA, "proseguir", "prosseguir", 0) /* linha 2706 */
R(R_INTEIRA, "Proseguir", "Prosseguir", 0) /* linha 2707 */
R(R_INTEIRA, "obstrói", "obstrui", 0) /* linha 2708 */
R(R_INTEIRA, "Obstrói", "Obstrui", 0) /* linha 2709 */
R(R_INTEIRA, "disvelo", "desvelo", 0) /* linha 2710 */
R(R_INTEIRA, "Disvelo", "Desvelo", 0) /* linha 2711 */
R(R_INTEIRA, "deshonrarem", "desonrarem", 0) /* linha 2712 */
R(R_INTEIRA, "Deshonrarem", "Desonrarem", 0) /* linha 2713 */
R(R_INTEIRA, "destrui-lo-ei", "destruí-lo-ei", 0) /* linha 2714 */
R(R_INTEIRA, "Destrui-lo-ei", "Destruí-lo-ei", 0) /* linha 2715 */
R(R_INTEIRA, "engola", "engula", 0) /* linha 2716 */
R(R_INTEIRA, "Engola", "Engula", 0) /* linha 2717 */
R(R_INTEIRA, "aiuda", "ainda", 0) /* linha 2718 */
R(R_INTEIRA, "Aiuda", "Ainda", 0) /* linha 2719 */
R(R_INTEIRA, "cubiçaram", "cobiçaram", 0) /* linha 2720 */
R(R_INTEIRA, "Cubiçaram", "Cobiçaram", 0) /* linha 2721 */
R(R_INTEIRA, "môa", "moa", 0) /* linha 2722 */
R(R_INTEIRA, "Môa", "Moa", 0) /* linha 2723 */
R(R_INTEIRA, "firamô-lo", "firamo-lo", 0) /* linha 2724 */
R(R_INTEIRA, "Firamô-lo", "Firamo-lo", 0) /* linha 2725 */
R(R_INTEIRA, "faxas", "faixas", 0) /* linha 2726 */
R(R_INTEIRA, "Faxas", "Faixas", 0) /* linha 2727 */
R(R_INTEIRA, "rodeiou", "rodeou", 0) /* linha 2728 */
R(R_INTEIRA, "Rodeiou", "Rodeou", 0) /* linha 2729 */
R(R_INTEIRA, "gloríeis", "glorieis", 0) /* linha 2730 */
R(R_INTEIRA, "Gloríeis", "Glorieis", 0) /* linha 2731 */
R(R_INTEIRA, "fazemô-lo", "fazemo-lo", 0) /* linha 2732 */
R(R_INTEIRA, "Fazemô-lo", "Fazemo-lo", 0) /* linha 2733 */
R(R_INTEIRA, "mandragoras", "mandrágoras", 0) /* linha 2734 */
R(R_INTEIRA, "Mandragoras", "Mandrágoras", 0) /* linha 2735 */
R(R_INTEIRA, "meis", "meio", 0) /* linha 2736 */
R(R_INTEIRA, "Meis", "Meio", 0) /* linha 2737 */
R(R_INTEIRA, "vestuario", "vestuário", 0) /* linha 2738 */
R(R_INTEIRA, "Vestuario", "Vestuário", 0) /* linha 2739 */
R(R_INTEIRA, "resurgirão", "ressurgirão", 0) /* linha 2740 */
R(R_INTEIRA, "Resurgirão", "Ressurgirão", 0) /* linha 2741 */
R(R_INTEIRA, "triumfa", "triunfa", 0) /* linha 2742 */
R(R_INTEIRA, "Triumfa", "Triunfa", 0) /* linha 2743 */
R(R_INTEIRA, "exhortou", "exortou", 0) /* linha 2744 */
R(R_INTEIRA, "Exhortou", "Exortou", 0) /* linha 2745 */
R(R_INTEIRA, "lancemô-lo", "lancemo-lo", 0) /* linha 2746 */
R(R_INTEIRA, "Lancemô-lo", "Lancemo-lo", 0) /* linha 2747 */
R(R_INTEIRA, "leôas", "leoas", 0) /* linha 2748 */
R(R_INTEIRA, "Leôas", "Leoas", 0) /* linha 2749 */
R(R_INTEIRA, "incircumcisas", "incircuncisas", 0) /* linha 2750 */
R(R_INTEIRA, "Incircumcisas", "Incircuncisas", 0) /* linha 2751 */
R(R_INTEIRA, "restituissem", "restituíssem", 0) /* linha 2752 */
R(R_INTEIRA, "Restituissem", "Restituíssem", 0) /* linha 2753 */
R(R_INTEIRA, "restituirem", "restituírem", 0) /* linha 2754 */
R(R_INTEIRA, "Restituirem", "Restituírem", 0) /* linha 2755 */
R(R_INTEIRA, "deshonre", "desonre", 0) /* linha 2756 */
R(R_INTEIRA, "Deshonre", "Desonre", 0) /* linha 2757 */
R(R_INTEIRA, "despertemô-lo", "despertemo-lo", 0) /* linha 2758 */
R(R_INTEIRA, "Despertemô-lo", "Despertemo-lo", 0) /* linha 2759 */
R(R_INTEIRA, "moe", "mói", 0) /* linha 2760 */
R(R_INTEIRA, "Moe", "Mói", 0) /* linha 2761 */
R(R_INTEIRA, "trazeim'os", "trazei-mos", 0) /* linha 2762 */
R(R_INTEIRA, "Trazeim'os", "Trazei-mos", 0) /* linha 2763 */
R(R_INTEIRA, "importunanado-o", "importunando-o", 0) /* linha 2764 */
R(R_INTEIRA, "Importunanado-o", "Importunando-o", 0) /* linha 2765 */
R(R_INTEIRA, "conducta", "conduta", 0) /* linha 2766 */
R(R_INTEIRA, "Conducta", "Conduta", 0) /* linha 2767 */
R(R_INTEIRA, "israhita", "israelita", 0) /* linha 2768 */
R(R_INTEIRA, "Israhita", "Israelita", 0) /* linha 2769 */
R(R_INTEIRA, "redemi-me", "redimi-me", 0) /* linha 2770 */
R(R_INTEIRA, "Redemi-me", "Redimi-me", 0) /* linha 2771 */
R(R_INTEIRA, "creai-os", "criai-os", 0) /* linha 2772 */
R(R_INTEIRA, "Creai-os", "Criai-os", 0) /* linha 2773 */
R(R_INTEIRA, "possuim", "possuem", 0) /* linha 2774 */
R(R_INTEIRA, "Possuim", "Possuem", 0) /* linha 2775 */
R(R_INTEIRA, "pégadas", "pegadas", 0) /* linha 2776 */
R(R_INTEIRA, "Pégadas", "Pegadas", 0) /* linha 2777 */
R(R_INTEIRA, "amplicíssimo", "amplíssimo", 0) /* linha 2778 */
R(R_INTEIRA, "Amplicíssimo", "Amplíssimo", 0) /* linha 2779 */
R(R_INTEIRA, "exhortávamos", "exortávamos", 0) /* linha 2780 */
R(R_INTEIRA, "Exhortávamos", "Exortávamos", 0) /* linha 2781 */
R(R_INTEIRA, "destruistes", "destruístes", 0) /* linha 2782 */
R(R_INTEIRA, "Destruistes", "Destruístes", 0) /* linha 2783 */
R(R_INTEIRA, "pifaros", "pífaros", 0) /* linha 2784 */
R(R_INTEIRA, "Pifaros", "Pífaros", 0) /* linha 2785 */
R(R_INTEIRA, "povosinho", "povozinho", 0) /* linha 2786 */
R(R_INTEIRA, "Povosinho", "Povozinho", 0) /* linha 2787 */
R(R_INTEIRA, "reune-te", "reúne-te", 0) /* linha 2788 */
R(R_INTEIRA, "Reune-te", "Reúne-te", 0) /* linha 2789 */
R(R_INTEIRA, "anciosos", "ansiosos", 0) /* linha 2790 */
R(R_INTEIRA, "Anciosos", "Ansiosos", 0) /* linha 2791 */
R(R_INTEIRA, "rôlo", "rolo", 0) /* linha 2792 */
R(R_INTEIRA, "Rôlo", "Rolo", 0) /* linha 2793 */
R(R_INTEIRA, "dôa", "doa", 0) /* linha 2794 */
R(R_INTEIRA, "Dôa", "Doa", 0) /* linha 2795 */
R(R_INTEIRA, "enchete", "enche-te", 0) /* linha 2796 */
R(R_INTEIRA, "Enchete", "Enche-te", 0) /* linha 2797 */
R(R_INTEIRA, "exhalar", "exalar", 0) /* linha 2798 */
R(R_INTEIRA, "Exhalar", "Exalar", 0) /* linha 2799 */
R(R_INTEIRA, "abrogou", "ab-rogou", 0) /* linha 2800 */
R(R_INTEIRA, "Abrogou", "Ab-rogou", 0) /* linha 2801 */
R(R_INTEIRA, "socoresse", "socorresse", 0) /* linha 2802 */
R(R_INTEIRA, "Socoresse", "Socorresse", 0) /* linha 2803 */
R(R_INTEIRA, "dar-vos-híamos", "dar-vos-íamos", 0) /* linha 2804 */
R(R_INTEIRA, "Dar-vos-híamos", "Dar-vos-íamos", 0) /* linha 2805 */
R(R_INTEIRA, "incircumcisãoh", "incircuncisão", 0) /* linha 2806 */
R(R_INTEIRA, "Incircumcisãoh", "Incircuncisão", 0) /* linha 2807 */
R(R_INTEIRA, "celebremô-lo", "celebremo-lo", 0) /* linha 2808 */
R(R_INTEIRA, "Celebremô-lo", "Celebremo-lo", 0) /* linha 2809 */
R(R_INTEIRA, "cérca", "cerca", 0) /* linha 2810 */
R(R_INTEIRA, "Cérca", "Cerca", 0) /* linha 2811 */
R(R_INTEIRA, "anhelais", "anelais", 0) /* linha 2812 */
R(R_INTEIRA, "Anhelais", "Anelais", 0) /* linha 2813 */
R(R_INTEIRA, "prosiga", "prossiga", 0) /* linha 2814 */
R(R_INTEIRA, "Prosiga", "Prossiga", 0) /* linha 2815 */
R(R_INTEIRA, "epicureos", "epicureus", 0) /* linha 2816 */
R(R_INTEIRA, "Epicureos", "Epicureus", 0) /* linha 2817 */
R(R_INTEIRA, "pórros", "porros", 0) /* linha 2818 */
R(R_INTEIRA, "Pórros", "Porros", 0) /* linha 2819 */
R(R_INTEIRA, "queimemô-los", "queimemo-los", 0) /* linha 2820 */
R(R_INTEIRA, "Queimemô-los", "Queimemo-los", 0) /* linha 2821 */
R(R_INTEIRA, "constituissem", "constituíssem", 0) /* linha 2822 */
R(R_INTEIRA, "Constituissem", "Constituíssem", 0) /* linha 2823 */
R(R_INTEIRA, "matemê-lo", "matemo-lo", 0) /* linha 2824 */
R(R_INTEIRA, "Matemê-lo", "Matemo-lo", 0) /* linha 2825 */
R(R_INTEIRA, "possuamô-la", "possuamo-la", 0) /* linha 2826 */
R(R_INTEIRA, "Possuamô-la", "Possuamo-la", 0) /* linha 2827 */
R(R_INTEIRA, "acquisição", "aquisição", 0) /* linha 2828 */
R(R_INTEIRA, "Acquisição", "Aquisição", 0) /* linha 2829 */
R(R_INTEIRA, "pêz", "pez", 0) /* linha 2830 */
R(R_INTEIRA, "Pêz", "Pez", 0) /* linha 2831 */
R(R_INTEIRA, "faziamos-lhe", "fazíamos-lhe", 0) /* linha 2832 */
R(R_INTEIRA, "Faziamos-lhe", "Fazíamos-lhe", 0) /* linha 2833 */
R(R_INTEIRA, "zêlo", "zelo", 0) /* linha 2834 */
R(R_INTEIRA, "Zêlo", "Zelo", 0) /* linha 2835 */
R(R_INTEIRA, "cincoentenarios", "cinquentenários", 0) /* linha 2836 */
R(R_INTEIRA, "Cincoentenarios", "Cinquentenários", 0) /* linha 2837 */
R(R_INTEIRA, "entregar-mô-lo", "entregar-mo-lo", 0) /* linha 2838 */
R(R_INTEIRA, "Entregar-mô-lo", "Entregar-mo-lo", 0) /* linha 2839 */
R(R_INTEIRA, "queimal-os-á", "queimá-los-á", 0) /* linha 2840 */
R(R_INTEIRA, "Queimal-os-á", "Queimá-los-á", 0) /* linha 2841 */
R(R_INTEIRA, "viêsseis", "viésseis", 0) /* linha 2842 */
R(R_INTEIRA, "Viêsseis", "Viésseis", 0) /* linha 2843 */
R(R_INTEIRA, "cambaleam", "cambaleiam", 0) /* linha 2844 */
R(R_INTEIRA, "Cambaleam", "Cambaleiam", 0) /* linha 2845 */
R(R_INTEIRA, "cubicemos", "cobicemos", 0) /* linha 2846 */
R(R_INTEIRA, "Cubicemos", "Cobicemos", 0) /* linha 2847 */
R(R_INTEIRA, "filosofos", "filósofos", 0) /* linha 2848 */
R(R_INTEIRA, "Filosofos", "Filósofos", 0) /* linha 2849 */
R(R_INTEIRA, "buscal-os-á", "buscá-los-á", 0) /* linha 2850 */
R(R_INTEIRA, "Buscal-os-á", "Buscá-los-á", 0) /* linha 2851 */
R(R_INTEIRA, "indignaes-vos", "indignais-vos", 0) /* linha 2852 */
R(R_INTEIRA, "Indignaes-vos", "Indignais-vos", 0) /* linha 2853 */
R(R_INTEIRA, "foramos", "fôramos", 0) /* linha 2854 */
R(R_INTEIRA, "Foramos", "Fôramos", 0) /* linha 2855 */
R(R_INTEIRA, "cubicei", "cobicei", 0) /* linha 2856 */
R(R_INTEIRA, "Cubicei", "Cobicei", 0) /* linha 2857 */
R(R_INTEIRA, "fêl-os", "fê-los", 0) /* linha 2858 */
R(R_INTEIRA, "Fêl-os", "Fê-los", 0) /* linha 2859 */
R(R_INTEIRA, "inutil", "inútil", 0) /* linha 2860 */
R(R_INTEIRA, "Inutil", "Inútil", 0) /* linha 2861 */
R(R_INTEIRA, "ultima", "última", 0) /* linha 2862 */
R(R_INTEIRA, "Ultima", "Última", 0) /* linha 2863 */
R(R_INTEIRA, "ultimas", "últimas", 0) /* linha 2864 */
R(R_INTEIRA, "Ultimas", "Últimas", 0) /* linha 2865 */
R(R_INTEIRA, "ultimo", "último", 0) /* linha 2866 */
R(R_INTEIRA, "Ultimo", "Último", 0) /* linha 2867 */
R(R_INTEIRA, "ultimos", "últimos", 0) /* linha 2868 */
R(R_INTEIRA, "Ultimos", "Últimos", 0) /* linha 2869 */
R(R_INTEIRA, "Asia", "Ásia", 0) /* linha 2870 */
R(R_INTEIRA, "Africa", "África", 0) /* linha 2871 */
R(R_INTEIRA, "eramos", "éramos", 0) /* linha 2872 */
R(R_INTEIRA, "Eramos", "Éramos", 0) /* linha 2873 */
R(R_INTEIRA, "ruido", "ruído", 0) /* linha 2874 */
R(R_INTEIRA, "Ruido", "Ruído", 0) /* linha 2875 */
/* Casos que dependem do sentido: só nas frases em que é nome */
R(R_TEXTO, "em duvida", "em dúvida", 0) /* linha 2882 */
R(R_TEXTO, "Sem duvida", "Sem dúvida", 0) /* linha 2882 */
R(R_TEXTO, "grande duvida", "grande dúvida", 0) /* linha 2883 */
R(R_TEXTO, "havia interprete", "havia intérprete", 0) /* linha 2884 */
R(R_TEXTO, "um interprete", "um intérprete", 0) /* linha 2884 */
R(R_TEXTO, "houver interprete", "houver intérprete", 0) /* linha 2885 */
R(R_TEXTO, "pouco celebre", "pouco célebre", 0) /* linha 2886 */
/* "-mor" não leva acento hoje: copeiro-mor, padeiro-mor, mordomo-mor */
R(R_TEXTO, "-mór", "-mor", 0) /* linha 2888 */
/* "porem" é verbo (para porem); só aqui é "porém" */
R(R_TEXTO, "olhos porem", "olhos porém", 0) /* linha 2890 */
/* At 27:16: passado do verbo poder */
R(R_TEXTO, "apenas podemos ganhar", "apenas pudemos ganhar", 0) /* linha 2892 */
/* 11. NOMES PRÓPRIOS (revisão de 27/11/2026)
       Adaptação ortográfica própria ao português (th, ph, y, ch=k, k, consoantes dobradas,
       finais -b/-d/-th com -e, acentos do Acordo) e formas de uso geral na língua.
       Nenhuma lista de edição moderna foi copiada. Na dúvida, ficou a forma de 1911.
       Fonte: biblia-build/nomes/nomes_todos.tsv */
R(R_INTEIRA, "Pocheret-hat-sebaim", "Poquerete-hat-sebaim", 0) /* linha 2902 */
R(R_INTEIRA, "Beerot-Bene-jaakan", "Beerote-Bene-jaacan", 0) /* linha 2903 */
R(R_INTEIRA, "Ashterot-karnaim", "Asterote-carnaim", 0) /* linha 2904 */
R(R_INTEIRA, "Esperal-os-híeis", "Esperá-los-íeis", 0) /* linha 2905 */
R(R_INTEIRA, "Merodach-baladan", "Merodaque-baladan", 0) /* linha 2906 */
R(R_INTEIRA, "Almon-diblataim", "Almom-diblataim", 0) /* linha 2907 */
R(R_INTEIRA, "Chefar-haamonai", "Quefar-haamonai", 0) /* linha 2908 */
R(R_INTEIRA, "Helkat-hazzurim", "Helcat-hazurim", 0) /* linha 2909 */
R(R_INTEIRA, "Pocheret-zebaim", "Poquerete-zebaim", 0) /* linha 2910 */
R(R_INTEIRA, "Quibrot-hataava", "Quibrote-hataava", 0) /* linha 2911 */
R(R_INTEIRA, "Sela-hamahlecot", "Sela-hamahlecote", 0) /* linha 2912 */
R(R_INTEIRA, "Shave-kiriataim", "Shave-quiriataim", 0) /* linha 2913 */
R(R_INTEIRA, "Tiglat-pilneser", "Tiglate-pilneser", 0) /* linha 2914 */
R(R_INTEIRA, "Tilgat-pilneser", "Tilgate-pilneser", 0) /* linha 2915 */
R(R_INTEIRA, "Abel-bet-maaca", "Abel-bete-maaca", 0) /* linha 2916 */
R(R_INTEIRA, "Bet-hamarcabot", "Bet-hamarcabote", 0) /* linha 2917 */
R(R_INTEIRA, "Hazer-hatichon", "Hazer-haticon", 0) /* linha 2918 */
R(R_INTEIRA, "Joseb-bashebet", "Josebe-bashebete", 0) /* linha 2919 */
R(R_INTEIRA, "Kibrot-hataava", "Quibrote-hataava", 0) /* linha 2920 */
R(R_INTEIRA, "Magor-missabib", "Magor-missabibe", 0) /* linha 2921 */
R(R_INTEIRA, "Tiglat-pileser", "Tiglate-pileser", 0) /* linha 2922 */
R(R_INTEIRA, "Chislot-tabor", "Quislote-tabor", 0) /* linha 2923 */
R(R_INTEIRA, "Conjurámo-nos", "Conjuramo-nos", 0) /* linha 2924 */
R(R_INTEIRA, "Estribaes-vos", "Estribais-vos", 0) /* linha 2925 */
R(R_INTEIRA, "Evil-merodach", "Evil-merodaque", 0) /* linha 2926 */
R(R_INTEIRA, "Exhortamo-vos", "Exortamo-vos", 0) /* linha 2927 */
R(R_INTEIRA, "Gerut-chimham", "Gerut-quimham", 0) /* linha 2928 */
R(R_INTEIRA, "Kiriat-jearim", "Quiriate-jearim", 0) /* linha 2929 */
R(R_INTEIRA, "Kiriot-hesron", "Quiriote-hesron", 0) /* linha 2930 */
R(R_INTEIRA, "Misrefot-main", "Misrefote-maim", 0) /* linha 2931 */
R(R_INTEIRA, "Nabucodonozor", "Nabucodonosor", 0) /* linha 2932 */
R(R_INTEIRA, "Quibrot-taava", "Quibrote-taava", 0) /* linha 2933 */
R(R_INTEIRA, "Quiriat-huzot", "Quiriate-huzote", 0) /* linha 2934 */
R(R_INTEIRA, "Quiriat-sefer", "Quiriate-sefer", 0) /* linha 2935 */
R(R_INTEIRA, "Zafnat-paneah", "Zafnate-paneah", 0) /* linha 2936 */
R(R_INTEIRA, "Abel-keramim", "Abel-queramim", 0) /* linha 2937 */
R(R_INTEIRA, "Adram-melech", "Adram-meleque", 0) /* linha 2938 */
R(R_INTEIRA, "Belteshazzar", "Beltessazar", 0) /* linha 2939 */
R(R_INTEIRA, "Bet-marcabot", "Bet-marcabote", 0) /* linha 2940 */
R(R_INTEIRA, "Chedorlaomer", "Quedorlaomer", 0) /* linha 2941 */
R(R_INTEIRA, "Evil-merodac", "Evil-merodaque", 0) /* linha 2942 */
R(R_INTEIRA, "feril-os-hei", "feri-los-ei", 0) /* linha 2943 */
R(R_INTEIRA, "Feril-os-hei", "Feri-los-ei", 0) /* linha 2944 */
R(R_INTEIRA, "Hazzelelponi", "Hazelelponi", 0) /* linha 2945 */
R(R_INTEIRA, "Hor-hagidgad", "Hor-hagidgade", 0) /* linha 2946 */
R(R_INTEIRA, "Jabez-gilead", "Jabez-gileade", 0) /* linha 2947 */
R(R_INTEIRA, "Jabéz-gilead", "Jabez-gileade", 0) /* linha 2948 */
R(R_INTEIRA, "Keren-hapuch", "Queren-hapuque", 0) /* linha 2949 */
R(R_INTEIRA, "Kiriat-sefer", "Quiriate-sefer", 0) /* linha 2950 */
R(R_INTEIRA, "Natan-melech", "Natã-meleque", 0) /* linha 2951 */
R(R_INTEIRA, "Nebus-hasban", "Nebus-hasbã", 0) /* linha 2952 */
R(R_INTEIRA, "Quiriat-arba", "Quiriate-arba", 0) /* linha 2953 */
R(R_INTEIRA, "Ramot-gilead", "Ramote-gileade", 0) /* linha 2954 */
R(R_INTEIRA, "Rimon-metoar", "Rimom-metoar", 0) /* linha 2955 */
R(R_INTEIRA, "Sihor-libnat", "Sihor-libnate", 0) /* linha 2956 */
R(R_INTEIRA, "Simron-meron", "Simrom-merom", 0) /* linha 2957 */
R(R_INTEIRA, "Timnat-heres", "Timnate-heres", 0) /* linha 2958 */
R(R_INTEIRA, "Timnat-serah", "Timnate-sera", 0) /* linha 2959 */
R(R_INTEIRA, "Traguemô-los", "Traguemo-los", 0) /* linha 2960 */
R(R_INTEIRA, "Abel-mehola", "Abel-meola", 0) /* linha 2961 */
R(R_INTEIRA, "Adoni-bezek", "Adoni-bezeque", 0) /* linha 2962 */
R(R_INTEIRA, "Anam-melech", "Anam-meleque", 0) /* linha 2963 */
R(R_INTEIRA, "Asdot-pisga", "Asdote-pisga", 0) /* linha 2964 */
R(R_INTEIRA, "Atarot-adar", "Atarote-adar", 0) /* linha 2965 */
R(R_INTEIRA, "Atrot-sofan", "Atrote-sofan", 0) /* linha 2966 */
R(R_INTEIRA, "Azmot-tabor", "Azmote-tabor", 0) /* linha 2967 */
R(R_INTEIRA, "Baalat-beer", "Baalate-beer", 0) /* linha 2968 */
R(R_INTEIRA, "Baal-hermon", "Baal-hermom", 0) /* linha 2969 */
R(R_INTEIRA, "Bene-jaakan", "Bene-jaacan", 0) /* linha 2970 */
R(R_INTEIRA, "Bet-azmavet", "Bete-azmavete", 0) /* linha 2971 */
R(R_INTEIRA, "Bet-jesimot", "Bet-jesimote", 0) /* linha 2972 */
R(R_INTEIRA, "Conductores", "Condutores", 0) /* linha 2973 */
R(R_INTEIRA, "Ebed-melech", "Ebede-meleque", 0) /* linha 2974 */
R(R_INTEIRA, "Eseon-geber", "Ezion-geber", 0) /* linha 2975 */
R(R_INTEIRA, "Esion-geber", "Ezion-geber", 0) /* linha 2976 */
R(R_INTEIRA, "Ezeon-geber", "Ezion-geber", 0) /* linha 2977 */
R(R_INTEIRA, "Hassar-sual", "Hasar-sual", 0) /* linha 2978 */
R(R_INTEIRA, "Hassar-susa", "Hasar-susa", 0) /* linha 2979 */
R(R_INTEIRA, "Jeberechias", "Jeberequias", 0) /* linha 2980 */
R(R_INTEIRA, "Jusab-hesed", "Jusabe-hesede", 0) /* linha 2981 */
R(R_INTEIRA, "Kir-hareset", "Quir-haresete", 0) /* linha 2982 */
R(R_INTEIRA, "Kiriat-arba", "Quiriate-arba", 0) /* linha 2983 */
R(R_INTEIRA, "Kiriat-arim", "Quiriate-arim", 0) /* linha 2984 */
R(R_INTEIRA, "Kiriat-baal", "Quiriate-baal", 0) /* linha 2985 */
R(R_INTEIRA, "Kiriat-sana", "Quiriate-sana", 0) /* linha 2986 */
R(R_INTEIRA, "Litostrótos", "Litostrotos", 0) /* linha 2987 */
R(R_INTEIRA, "Melchisedec", "Melquisedeque", 0) /* linha 2988 */
R(R_INTEIRA, "Melchizedec", "Melquisedeque", 0) /* linha 2989 */
R(R_INTEIRA, "Nebuzaradan", "Nebuzaradã", 0) /* linha 2990 */
R(R_INTEIRA, "Obedeecemos", "Obedecemos", 0) /* linha 2991 */
R(R_INTEIRA, "Ramat-lechi", "Ramate-lequi", 0) /* linha 2992 */
R(R_INTEIRA, "Ramat-mispe", "Ramate-mispe", 0) /* linha 2993 */
R(R_INTEIRA, "Rimon-parez", "Rimom-perez", 0) /* linha 2994 */
R(R_INTEIRA, "Rimon-perez", "Rimom-perez", 0) /* linha 2995 */
R(R_INTEIRA, "Sucot-benot", "Sucote-benote", 0) /* linha 2996 */
R(R_INTEIRA, "Taanat-silo", "Taanate-silo", 0) /* linha 2997 */
R(R_INTEIRA, "Timnat-sera", "Timnate-sera", 0) /* linha 2998 */
R(R_INTEIRA, "Tocámos-vos", "Tocamos-vos", 0) /* linha 2999 */
R(R_INTEIRA, "Adonizedek", "Adonizedeque", 0) /* linha 3000 */
R(R_INTEIRA, "Adramelech", "Adrameleque", 0) /* linha 3001 */
R(R_INTEIRA, "Aholibamah", "Aholibama", 0) /* linha 3002 */
R(R_INTEIRA, "Alonbachut", "Alombacute", 0) /* linha 3003 */
R(R_INTEIRA, "Amalekitas", "Amalequitas", 0) /* linha 3004 */
R(R_INTEIRA, "Aquimelech", "Aquimeleque", 0) /* linha 3005 */
R(R_INTEIRA, "Aristobulo", "Aristóbulo", 0) /* linha 3006 */
R(R_INTEIRA, "Asar-hadon", "Asar-hadom", 0) /* linha 3007 */
R(R_INTEIRA, "Baal-berit", "Baal-berite", 0) /* linha 3008 */
R(R_INTEIRA, "Baal-hamon", "Baal-hamom", 0) /* linha 3009 */
R(R_INTEIRA, "Baal-zebub", "Baal-zebube", 0) /* linha 3010 */
R(R_INTEIRA, "Baal-zefon", "Baal-zefom", 0) /* linha 3011 */
R(R_INTEIRA, "Bamot-baal", "Bamote-baal", 0) /* linha 3012 */
R(R_INTEIRA, "Bat-arabim", "Bate-arabim", 0) /* linha 3013 */
R(R_INTEIRA, "Belshazzar", "Belsazar", 0) /* linha 3014 */
R(R_INTEIRA, "Bene-berak", "Bene-beraque", 0) /* linha 3015 */
R(R_INTEIRA, "Bet-acerem", "Bete-acerem", 0) /* linha 3016 */
R(R_INTEIRA, "Bet-cherem", "Bet-querem", 0) /* linha 3017 */
R(R_INTEIRA, "Bet-lebaot", "Bet-lebaote", 0) /* linha 3018 */
R(R_INTEIRA, "Bet-rechob", "Bet-recobe", 0) /* linha 3019 */
R(R_INTEIRA, "Concluimos", "Concluímos", 0) /* linha 3020 */
R(R_INTEIRA, "Filadelfia", "Filadélfia", 0) /* linha 3021 */
R(R_INTEIRA, "Hamolechet", "Hamolequet", 0) /* linha 3022 */
R(R_INTEIRA, "Hasarmavet", "Hazarmavet", 0) /* linha 3023 */
R(R_INTEIRA, "Hermogenes", "Hermógenes", 0) /* linha 3024 */
R(R_INTEIRA, "Hierapolis", "Hierápolis", 0) /* linha 3025 */
R(R_INTEIRA, "Isbi-benob", "Isbi-benobe", 0) /* linha 3026 */
R(R_INTEIRA, "Jesua-joab", "Jesua-joabe", 0) /* linha 3027 */
R(R_INTEIRA, "Lachai-roi", "Lahai-roi", 0) /* linha 3028 */
R(R_INTEIRA, "Machnadbai", "Macnadbai", 0) /* linha 3029 */
R(R_INTEIRA, "Mahalaleel", "Mahalalel", 0) /* linha 3030 */
R(R_INTEIRA, "Malchi-sua", "Malquisua", 0) /* linha 3031 */
R(R_INTEIRA, "Mehetabeel", "Mehetabel", 0) /* linha 3032 */
R(R_INTEIRA, "Merib-baal", "Meribe-baal", 0) /* linha 3033 */
R(R_INTEIRA, "Mezezabeel", "Mesezabeel", 0) /* linha 3034 */
R(R_INTEIRA, "Migdal-gad", "Migdal-gade", 0) /* linha 3035 */
R(R_INTEIRA, "Padan-aram", "Padã-arã", 0) /* linha 3036 */
R(R_INTEIRA, "Pahat-moab", "Paate-moabe", 0) /* linha 3037 */
R(R_INTEIRA, "Pi-hahirot", "Pi-hairote", 0) /* linha 3038 */
R(R_INTEIRA, "Pozeram-te", "Puseram-te", 0) /* linha 3039 */
R(R_INTEIRA, "Prohibindo", "Proibindo", 0) /* linha 3040 */
R(R_INTEIRA, "Proseguiam", "Prosseguiam", 0) /* linha 3041 */
R(R_INTEIRA, "Regemelech", "Regemeleque", 0) /* linha 3042 */
R(R_INTEIRA, "Rehobot-Ir", "Reobote-Ir", 0) /* linha 3043 */
R(R_INTEIRA, "Samotracia", "Samotrácia", 0) /* linha 3044 */
R(R_INTEIRA, "Senacherib", "Senaqueribe", 0) /* linha 3045 */
R(R_INTEIRA, "Senaquerib", "Senaqueribe", 0) /* linha 3046 */
R(R_INTEIRA, "Tiberiades", "Tiberíades", 0) /* linha 3047 */
R(R_INTEIRA, "Uzzen-sera", "Uzen-sera", 0) /* linha 3048 */
R(R_INTEIRA, "Abed-nego", "Abede-nego", 0) /* linha 3049 */
R(R_INTEIRA, "Abi-albon", "Abi-albom", 0) /* linha 3050 */
R(R_INTEIRA, "Achitofel", "Aquitofel", 0) /* linha 3051 */
R(R_INTEIRA, "Ahisamach", "Ahisamaque", 0) /* linha 3052 */
R(R_INTEIRA, "Alamelech", "Alameleque", 0) /* linha 3053 */
R(R_INTEIRA, "Amaldiçôa", "Amaldiçoa", 0) /* linha 3054 */
R(R_INTEIRA, "Andronico", "Andrônico", 0) /* linha 3055 */
R(R_INTEIRA, "Antiochia", "Antioquia", 0) /* linha 3056 */
R(R_INTEIRA, "Apromptai", "Aprontai", 0) /* linha 3057 */
R(R_INTEIRA, "Armagedon", "Armagedom", 0) /* linha 3058 */
R(R_INTEIRA, "Asincrito", "Assíncrito", 0) /* linha 3059 */
R(R_INTEIRA, "Baal-meon", "Baal-meom", 0) /* linha 3060 */
R(R_INTEIRA, "Bakbakkar", "Bacbacar", 0) /* linha 3061 */
R(R_INTEIRA, "Bakbukias", "Bacbuquias", 0) /* linha 3062 */
R(R_INTEIRA, "Baracheel", "Baraqueel", 0) /* linha 3063 */
R(R_INTEIRA, "Barachias", "Baraquias", 0) /* linha 3064 */
R(R_INTEIRA, "Ben-deker", "Ben-dequer", 0) /* linha 3065 */
R(R_INTEIRA, "Ben-hadad", "Ben-hadade", 0) /* linha 3066 */
R(R_INTEIRA, "Berechias", "Berequias", 0) /* linha 3067 */
R(R_INTEIRA, "Bet-araba", "Bete-araba", 0) /* linha 3068 */
R(R_INTEIRA, "Bet-arbel", "Bete-arbel", 0) /* linha 3069 */
R(R_INTEIRA, "Bet-lehem", "Belém", 0) /* linha 3070 */
R(R_INTEIRA, "Bet-palet", "Bet-pelete", 0) /* linha 3071 */
R(R_INTEIRA, "Bet-pelet", "Bet-pelete", 0) /* linha 3072 */
R(R_INTEIRA, "Capernaum", "Cafarnaum", 0) /* linha 3073 */
R(R_INTEIRA, "Carchemis", "Carquemis", 0) /* linha 3074 */
R(R_INTEIRA, "Chenanias", "Quenanias", 0) /* linha 3075 */
R(R_INTEIRA, "Decapolis", "Decápolis", 0) /* linha 3076 */
R(R_INTEIRA, "Dibon-gad", "Dibon-gade", 0) /* linha 3077 */
R(R_INTEIRA, "Emekkesis", "Emequesis", 0) /* linha 3078 */
R(R_INTEIRA, "Exhaustos", "Exaustos", 0) /* linha 3079 */
R(R_INTEIRA, "Genezaret", "Genesaré", 0) /* linha 3080 */
R(R_INTEIRA, "Ismachias", "Ismaquias", 0) /* linha 3081 */
R(R_INTEIRA, "Jeheiakim", "Jeheiaquim", 0) /* linha 3082 */
R(R_INTEIRA, "Jehizkias", "Jehizquias", 0) /* linha 3083 */
R(R_INTEIRA, "Jehoiarib", "Jehoiaribe", 0) /* linha 3084 */
R(R_INTEIRA, "Jekabseel", "Jecabseel", 0) /* linha 3085 */
R(R_INTEIRA, "Jerubeset", "Jerubesete", 0) /* linha 3086 */
R(R_INTEIRA, "Jeshoaias", "Jeshoaías", 0) /* linha 3087 */
R(R_INTEIRA, "Josbekasa", "Josbecasa", 0) /* linha 3088 */
R(R_INTEIRA, "Kir-heres", "Quir-heres", 0) /* linha 3089 */
R(R_INTEIRA, "Kiriataim", "Quiriataim", 0) /* linha 3090 */
R(R_INTEIRA, "Machbanai", "Macbanai", 0) /* linha 3091 */
R(R_INTEIRA, "Machpelah", "Macpela", 0) /* linha 3092 */
R(R_INTEIRA, "Malachias", "Malaquias", 0) /* linha 3093 */
R(R_INTEIRA, "Malchiram", "Malquiram", 0) /* linha 3094 */
R(R_INTEIRA, "Malchisua", "Malquisua", 0) /* linha 3095 */
R(R_INTEIRA, "Mardocheo", "Mardoqueu", 0) /* linha 3096 */
R(R_INTEIRA, "Mefiboset", "Mefibosete", 0) /* linha 3097 */
R(R_INTEIRA, "Mesezabel", "Mesezabeel", 0) /* linha 3098 */
R(R_INTEIRA, "Mesilemit", "Mesilemite", 0) /* linha 3099 */
R(R_INTEIRA, "Mesilemot", "Mesilemote", 0) /* linha 3100 */
R(R_INTEIRA, "Mesulemet", "Mesulemete", 0) /* linha 3101 */
R(R_INTEIRA, "Metusalah", "Matusalém", 0) /* linha 3102 */
R(R_INTEIRA, "Mikametat", "Micmetate", 0) /* linha 3103 */
R(R_INTEIRA, "Nafat-dor", "Nafate-dor", 0) /* linha 3104 */
R(R_INTEIRA, "Nafot-dor", "Nafote-dor", 0) /* linha 3105 */
R(R_INTEIRA, "Nicopolis", "Nicópolis", 0) /* linha 3106 */
R(R_INTEIRA, "Obedeecei", "Obedecei", 0) /* linha 3107 */
R(R_INTEIRA, "Peres-uza", "Perez-uza", 0) /* linha 3108 */
R(R_INTEIRA, "Petachias", "Petaquias", 0) /* linha 3109 */
R(R_INTEIRA, "Protector", "Protetor", 0) /* linha 3110 */
R(R_INTEIRA, "Sechanias", "Secanias", 0) /* linha 3111 */
R(R_INTEIRA, "Semachias", "Semaquias", 0) /* linha 3112 */
R(R_INTEIRA, "Semiramot", "Semiramote", 0) /* linha 3113 */
R(R_INTEIRA, "Shigionot", "Shigionote", 0) /* linha 3114 */
R(R_INTEIRA, "Tachemoni", "Taquemoni", 0) /* linha 3115 */
R(R_INTEIRA, "Tachfanes", "Tahpanhes", 0) /* linha 3116 */
R(R_INTEIRA, "Tachpenes", "Tacpenes", 0) /* linha 3117 */
R(R_INTEIRA, "Zerachias", "Zeraquias", 0) /* linha 3118 */
R(R_INTEIRA, "Abikeila", "Abiqueila", 0) /* linha 3119 */
R(R_INTEIRA, "Abinadab", "Abinadabe", 0) /* linha 3120 */
R(R_INTEIRA, "Achinoam", "Aquinoam", 0) /* linha 3121 */
R(R_INTEIRA, "Adonikam", "Adonicam", 0) /* linha 3122 */
R(R_INTEIRA, "Ahasuero", "Assuero", 0) /* linha 3123 */
R(R_INTEIRA, "Ahimelek", "Ahimeleque", 0) /* linha 3124 */
R(R_INTEIRA, "Ahinadab", "Ahinadabe", 0) /* linha 3125 */
R(R_INTEIRA, "Amomtoei", "Amontoei", 0) /* linha 3126 */
R(R_INTEIRA, "Amorrheo", "Amorreu", 0) /* linha 3127 */
R(R_INTEIRA, "Amorrheu", "Amorreu", 0) /* linha 3128 */
R(R_INTEIRA, "Anacarat", "Anacarate", 0) /* linha 3129 */
R(R_INTEIRA, "Apolonia", "Apolônia", 0) /* linha 3130 */
R(R_INTEIRA, "Archelau", "Arquelau", 0) /* linha 3131 */
R(R_INTEIRA, "Areopago", "Areópago", 0) /* linha 3132 */
R(R_INTEIRA, "Arimatea", "Arimateia", 0) /* linha 3133 */
R(R_INTEIRA, "Asquelon", "Ascalom", 0) /* linha 3134 */
R(R_INTEIRA, "Baal-gad", "Baal-gade", 0) /* linha 3135 */
R(R_INTEIRA, "Baalpeor", "Baal-peor", 0) /* linha 3136 */
R(R_INTEIRA, "Barrabas", "Barrabás", 0) /* linha 3137 */
R(R_INTEIRA, "Bartimeo", "Bartimeu", 0) /* linha 3138 */
R(R_INTEIRA, "Bat-seba", "Bate-seba", 0) /* linha 3139 */
R(R_INTEIRA, "Bechorat", "Becorate", 0) /* linha 3140 */
R(R_INTEIRA, "Beelzebú", "Beelzebu", 0) /* linha 3141 */
R(R_INTEIRA, "Benchail", "Benquail", 0) /* linha 3142 */
R(R_INTEIRA, "Benhadad", "Ben-hadade", 0) /* linha 3143 */
R(R_INTEIRA, "Benzohet", "Benzohete", 0) /* linha 3144 */
R(R_INTEIRA, "Bet-anat", "Bete-anate", 0) /* linha 3145 */
R(R_INTEIRA, "Bet-anot", "Bete-anote", 0) /* linha 3146 */
R(R_INTEIRA, "Bet-aram", "Bete-aram", 0) /* linha 3147 */
R(R_INTEIRA, "Bet-aven", "Bete-aven", 0) /* linha 3148 */
R(R_INTEIRA, "Bet-eked", "Bet-equede", 0) /* linha 3149 */
R(R_INTEIRA, "Bet-emek", "Bet-emeque", 0) /* linha 3150 */
R(R_INTEIRA, "Birzavit", "Birzavite", 0) /* linha 3151 */
R(R_INTEIRA, "Chaldeus", "Caldeus", 0) /* linha 3152 */
R(R_INTEIRA, "Chanaana", "Canaana", 0) /* linha 3153 */
R(R_INTEIRA, "Chelubai", "Quelubai", 0) /* linha 3154 */
R(R_INTEIRA, "Chenaana", "Quenaana", 0) /* linha 3155 */
R(R_INTEIRA, "Chesulot", "Quesulote", 0) /* linha 3156 */
R(R_INTEIRA, "Chineret", "Cinerete", 0) /* linha 3157 */
R(R_INTEIRA, "Chinerot", "Cinerote", 0) /* linha 3158 */
R(R_INTEIRA, "Chorazin", "Corazin", 0) /* linha 3159 */
R(R_INTEIRA, "Cubiçais", "Cobiçais", 0) /* linha 3160 */
R(R_INTEIRA, "Dalmacia", "Dalmácia", 0) /* linha 3161 */
R(R_INTEIRA, "Dionisio", "Dionísio", 0) /* linha 3162 */
R(R_INTEIRA, "Elifelet", "Elifelete", 0) /* linha 3163 */
R(R_INTEIRA, "Elihoref", "Elihorefe", 0) /* linha 3164 */
R(R_INTEIRA, "Filistia", "Filístia", 0) /* linha 3165 */
R(R_INTEIRA, "Filologo", "Filólogo", 0) /* linha 3166 */
R(R_INTEIRA, "Gomorrah", "Gomorra", 0) /* linha 3167 */
R(R_INTEIRA, "Gomorrha", "Gomorra", 0) /* linha 3168 */
R(R_INTEIRA, "Grangeai", "Granjeai", 0) /* linha 3169 */
R(R_INTEIRA, "grangeai", "granjeai", 0) /* linha 3170 */
R(R_INTEIRA, "Haldrach", "Haldraque", 0) /* linha 3171 */
R(R_INTEIRA, "Hamelech", "Hameleque", 0) /* linha 3172 */
R(R_INTEIRA, "Jecholia", "Jecolia", 0) /* linha 3173 */
R(R_INTEIRA, "Jehezkel", "Jehezquel", 0) /* linha 3174 */
R(R_INTEIRA, "Jekamias", "Jecamias", 0) /* linha 3175 */
R(R_INTEIRA, "Jekutiel", "Jecutiel", 0) /* linha 3176 */
R(R_INTEIRA, "Jesebeab", "Jesebeabe", 0) /* linha 3177 */
R(R_INTEIRA, "Jochebed", "Joquebede", 0) /* linha 3178 */
R(R_INTEIRA, "Jogbehah", "Jogbeha", 0) /* linha 3179 */
R(R_INTEIRA, "Kadmoneo", "Cadmoneu", 0) /* linha 3180 */
R(R_INTEIRA, "Kehelata", "Quehelata", 0) /* linha 3181 */
R(R_INTEIRA, "Kirheres", "Quir-heres", 0) /* linha 3182 */
R(R_INTEIRA, "Leviatan", "Leviatã", 0) /* linha 3183 */
R(R_INTEIRA, "Machbena", "Macbena", 0) /* linha 3184 */
R(R_INTEIRA, "Machpela", "Macpela", 0) /* linha 3185 */
R(R_INTEIRA, "Mahaziot", "Mahaziote", 0) /* linha 3186 */
R(R_INTEIRA, "Malchias", "Malquias", 0) /* linha 3187 */
R(R_INTEIRA, "Malchiel", "Malquiel", 0) /* linha 3188 */
R(R_INTEIRA, "Matusala", "Matusalém", 0) /* linha 3189 */
R(R_INTEIRA, "Melchias", "Melquias", 0) /* linha 3190 */
R(R_INTEIRA, "Merodach", "Merodaque", 0) /* linha 3191 */
R(R_INTEIRA, "Messulam", "Mesulam", 0) /* linha 3192 */
R(R_INTEIRA, "Metusala", "Matusalém", 0) /* linha 3193 */
R(R_INTEIRA, "Michaias", "Micaías", 0) /* linha 3194 */
R(R_INTEIRA, "Mikmetat", "Micmetate", 0) /* linha 3195 */
R(R_INTEIRA, "Mikneias", "Micneias", 0) /* linha 3196 */
R(R_INTEIRA, "Miniamin", "Miniamim", 0) /* linha 3197 */
R(R_INTEIRA, "Misperet", "Misperete", 0) /* linha 3198 */
R(R_INTEIRA, "Mitredat", "Mitredate", 0) /* linha 3199 */
R(R_INTEIRA, "Mitsraim", "Mizraim", 0) /* linha 3200 */
R(R_INTEIRA, "Naftuhim", "Naftuim", 0) /* linha 3201 */
R(R_INTEIRA, "Nahaliel", "Naaliel", 0) /* linha 3202 */
R(R_INTEIRA, "Nahamani", "Naamani", 0) /* linha 3203 */
R(R_INTEIRA, "Nahasson", "Naassom", 0) /* linha 3204 */
R(R_INTEIRA, "Nehemias", "Neemias", 0) /* linha 3205 */
R(R_INTEIRA, "Nehustan", "Neustã", 0) /* linha 3206 */
R(R_INTEIRA, "Petahias", "Petaías", 0) /* linha 3207 */
R(R_INTEIRA, "Prochoro", "Prócoro", 0) /* linha 3208 */
R(R_INTEIRA, "Puteolos", "Putéolos", 0) /* linha 3209 */
R(R_INTEIRA, "Quedemot", "Quedemote", 0) /* linha 3210 */
R(R_INTEIRA, "Rahmeses", "Rameses", 0) /* linha 3211 */
R(R_INTEIRA, "Ramesses", "Rameses", 0) /* linha 3212 */
R(R_INTEIRA, "Reelaias", "Reelaías", 0) /* linha 3213 */
R(R_INTEIRA, "Rehabias", "Reabias", 0) /* linha 3214 */
R(R_INTEIRA, "Restitue", "Restitui", 0) /* linha 3215 */
R(R_INTEIRA, "Saalabin", "Saalabim", 0) /* linha 3216 */
R(R_INTEIRA, "Sabtecha", "Sabteca", 0) /* linha 3217 */
R(R_INTEIRA, "Sahasima", "Saasima", 0) /* linha 3218 */
R(R_INTEIRA, "Salechet", "Salequete", 0) /* linha 3219 */
R(R_INTEIRA, "Sanbalat", "Sambalate", 0) /* linha 3220 */
R(R_INTEIRA, "Sanherib", "Sanheribe", 0) /* linha 3221 */
R(R_INTEIRA, "Seleucia", "Selêucia", 0) /* linha 3222 */
R(R_INTEIRA, "Semeiais", "Semeais", 0) /* linha 3223 */
R(R_INTEIRA, "Senazzar", "Senazar", 0) /* linha 3224 */
R(R_INTEIRA, "Shelomit", "Selomite", 0) /* linha 3225 */
R(R_INTEIRA, "Shemaias", "Semaías", 0) /* linha 3226 */
R(R_INTEIRA, "Sheshach", "Sesaque", 0) /* linha 3227 */
R(R_INTEIRA, "Sibechai", "Sibecai", 0) /* linha 3228 */
R(R_INTEIRA, "Sidonios", "Sidônios", 0) /* linha 3229 */
R(R_INTEIRA, "Sintiche", "Síntique", 0) /* linha 3230 */
R(R_INTEIRA, "Sostenes", "Sóstenes", 0) /* linha 3231 */
R(R_INTEIRA, "Tabrimon", "Tabrimom", 0) /* linha 3232 */
R(R_INTEIRA, "Tanhumet", "Tanhumete", 0) /* linha 3233 */
R(R_INTEIRA, "Tarshish", "Társis", 0) /* linha 3234 */
R(R_INTEIRA, "Tel-abib", "Tel-abibe", 0) /* linha 3235 */
R(R_INTEIRA, "Trogilio", "Trogílio", 0) /* linha 3236 */
R(R_INTEIRA, "Zedekias", "Zedequias", 0) /* linha 3237 */
R(R_INTEIRA, "Abiasaf", "Abiasafe", 0) /* linha 3238 */
R(R_INTEIRA, "Achaico", "Acaico", 0) /* linha 3239 */
R(R_INTEIRA, "Achmeta", "Acmeta", 0) /* linha 3240 */
R(R_INTEIRA, "Ahieser", "Ahiezer", 0) /* linha 3241 */
R(R_INTEIRA, "Aholiab", "Aholiabe", 0) /* linha 3242 */
R(R_INTEIRA, "Ahuzzam", "Ahuzam", 0) /* linha 3243 */
R(R_INTEIRA, "Ahuzzat", "Ahuzate", 0) /* linha 3244 */
R(R_INTEIRA, "Aijalon", "Aijalom", 0) /* linha 3245 */
R(R_INTEIRA, "Akrabim", "Acrabim", 0) /* linha 3246 */
R(R_INTEIRA, "Almodad", "Almodade", 0) /* linha 3247 */
R(R_INTEIRA, "Amomtoa", "Amontoa", 0) /* linha 3248 */
R(R_INTEIRA, "Apolion", "Apoliom", 0) /* linha 3249 */
R(R_INTEIRA, "A'quele", "Aquele", 0) /* linha 3250 */
R(R_INTEIRA, "Archipo", "Arquipo", 0) /* linha 3251 */
R(R_INTEIRA, "Ascalon", "Ascalom", 0) /* linha 3252 */
R(R_INTEIRA, "Askelon", "Ascalom", 0) /* linha 3253 */
R(R_INTEIRA, "Asmavet", "Azmavete", 0) /* linha 3254 */
R(R_INTEIRA, "Astarot", "Astarote", 0) /* linha 3255 */
R(R_INTEIRA, "Astoret", "Astorete", 0) /* linha 3256 */
R(R_INTEIRA, "Azmavet", "Azmavete", 0) /* linha 3257 */
R(R_INTEIRA, "Azrikam", "Azricam", 0) /* linha 3258 */
R(R_INTEIRA, "Barabás", "Barrabás", 0) /* linha 3259 */
R(R_INTEIRA, "Basemat", "Basemate", 0) /* linha 3260 */
R(R_INTEIRA, "Batseba", "Bate-seba", 0) /* linha 3261 */
R(R_INTEIRA, "Bat-sua", "Bate-sua", 0) /* linha 3262 */
R(R_INTEIRA, "Behemot", "Beemote", 0) /* linha 3263 */
R(R_INTEIRA, "Beracha", "Beraca", 0) /* linha 3264 */
R(R_INTEIRA, "Berodac", "Berodaque", 0) /* linha 3265 */
R(R_INTEIRA, "Besemat", "Basemate", 0) /* linha 3266 */
R(R_INTEIRA, "Betaven", "Bete-aven", 0) /* linha 3267 */
R(R_INTEIRA, "Betfage", "Betfagé", 0) /* linha 3268 */
R(R_INTEIRA, "Betoron", "Bet-horon", 0) /* linha 3269 */
R(R_INTEIRA, "Bet-sur", "Bet-zur", 0) /* linha 3270 */
R(R_INTEIRA, "Bukkias", "Buquias", 0) /* linha 3271 */
R(R_INTEIRA, "Chefira", "Quefira", 0) /* linha 3272 */
R(R_INTEIRA, "Chelbon", "Quelbon", 0) /* linha 3273 */
R(R_INTEIRA, "Cheluhi", "Queluhi", 0) /* linha 3274 */
R(R_INTEIRA, "Chenani", "Quenani", 0) /* linha 3275 */
R(R_INTEIRA, "Chileab", "Quileabe", 0) /* linha 3276 */
R(R_INTEIRA, "Chilion", "Quilion", 0) /* linha 3277 */
R(R_INTEIRA, "Chimham", "Quimham", 0) /* linha 3278 */
R(R_INTEIRA, "Chislon", "Quislon", 0) /* linha 3279 */
R(R_INTEIRA, "Chitlis", "Quitlis", 0) /* linha 3280 */
R(R_INTEIRA, "Cineret", "Cinerete", 0) /* linha 3281 */
R(R_INTEIRA, "Cinerot", "Cinerote", 0) /* linha 3282 */
R(R_INTEIRA, "Cirenio", "Cirênio", 0) /* linha 3283 */
R(R_INTEIRA, "Claudia", "Cláudia", 0) /* linha 3284 */
R(R_INTEIRA, "Daberat", "Daberate", 0) /* linha 3285 */
R(R_INTEIRA, "Dabeset", "Dabesete", 0) /* linha 3286 */
R(R_INTEIRA, "Damaris", "Dâmaris", 0) /* linha 3287 */
R(R_INTEIRA, "Ebiasaf", "Ebiasafe", 0) /* linha 3288 */
R(R_INTEIRA, "Eleazer", "Eleasar", 0) /* linha 3289 */
R(R_INTEIRA, "Eliasaf", "Eliasafe", 0) /* linha 3290 */
R(R_INTEIRA, "Eltekon", "Eltecon", 0) /* linha 3291 */
R(R_INTEIRA, "Epéneto", "Epêneto", 0) /* linha 3292 */
R(R_INTEIRA, "Euticho", "Êutico", 0) /* linha 3293 */
R(R_INTEIRA, "Hachila", "Haquila", 0) /* linha 3294 */
R(R_INTEIRA, "Hadoran", "Hadoram", 0) /* linha 3295 */
R(R_INTEIRA, "Havilah", "Havila", 0) /* linha 3296 */
R(R_INTEIRA, "Henadad", "Henadade", 0) /* linha 3297 */
R(R_INTEIRA, "Hezroma", "Hezrona", 0) /* linha 3298 */
R(R_INTEIRA, "Hidekel", "Hidequel", 0) /* linha 3299 */
R(R_INTEIRA, "Himeneo", "Himeneu", 0) /* linha 3300 */
R(R_INTEIRA, "instrue", "instrui", 0) /* linha 3301 */
R(R_INTEIRA, "Instrue", "Instrui", 0) /* linha 3302 */
R(R_INTEIRA, "Ishmael", "Ismael", 0) /* linha 3303 */
R(R_INTEIRA, "Jaakoba", "Jaacoba", 0) /* linha 3304 */
R(R_INTEIRA, "Jamlech", "Jamleque", 0) /* linha 3305 */
R(R_INTEIRA, "Jekamam", "Jecamam", 0) /* linha 3306 */
R(R_INTEIRA, "Jeremat", "Jeremate", 0) /* linha 3307 */
R(R_INTEIRA, "Jeremot", "Jeremote", 0) /* linha 3308 */
R(R_INTEIRA, "Jerimot", "Jerimote", 0) /* linha 3309 */
R(R_INTEIRA, "Jesaias", "Jesaías", 0) /* linha 3310 */
R(R_INTEIRA, "Joachaz", "Joacaz", 0) /* linha 3311 */
R(R_INTEIRA, "Joachim", "Joaquim", 0) /* linha 3312 */
R(R_INTEIRA, "Joachin", "Joaquim", 0) /* linha 3313 */
R(R_INTEIRA, "Joiarib", "Joiaribe", 0) /* linha 3314 */
R(R_INTEIRA, "Jojarib", "Joiaribe", 0) /* linha 3315 */
R(R_INTEIRA, "Jokdeam", "Jocdeam", 0) /* linha 3316 */
R(R_INTEIRA, "Jokmeam", "Jocmeam", 0) /* linha 3317 */
R(R_INTEIRA, "Jokneam", "Jocneam", 0) /* linha 3318 */
R(R_INTEIRA, "Jokteel", "Jocteel", 0) /* linha 3319 */
R(R_INTEIRA, "Jonadab", "Jonadabe", 0) /* linha 3320 */
R(R_INTEIRA, "Jonatan", "Jônatas", 0) /* linha 3321 */
R(R_INTEIRA, "Jorkeam", "Jorqueam", 0) /* linha 3322 */
R(R_INTEIRA, "Josadac", "Josadaque", 0) /* linha 3323 */
R(R_INTEIRA, "Josadak", "Josadaque", 0) /* linha 3324 */
R(R_INTEIRA, "Josebat", "Josebate", 0) /* linha 3325 */
R(R_INTEIRA, "Jozabad", "Jozabade", 0) /* linha 3326 */
R(R_INTEIRA, "Jozabat", "Jozabade", 0) /* linha 3327 */
R(R_INTEIRA, "Jupiter", "Júpiter", 0) /* linha 3328 */
R(R_INTEIRA, "Kabseel", "Cabseel", 0) /* linha 3329 */
R(R_INTEIRA, "Kadmiel", "Cadmiel", 0) /* linha 3330 */
R(R_INTEIRA, "Kazerim", "Cazerim", 0) /* linha 3331 */
R(R_INTEIRA, "Kedemot", "Quedemote", 0) /* linha 3332 */
R(R_INTEIRA, "Kelaias", "Quelaías", 0) /* linha 3333 */
R(R_INTEIRA, "Kelitas", "Quelitas", 0) /* linha 3334 */
R(R_INTEIRA, "Kenezeo", "Quenezeu", 0) /* linha 3335 */
R(R_INTEIRA, "Kesalon", "Quesalon", 0) /* linha 3336 */
R(R_INTEIRA, "Kibsaim", "Quibsaim", 0) /* linha 3337 */
R(R_INTEIRA, "Kolaias", "Colaías", 0) /* linha 3338 */
R(R_INTEIRA, "Koritas", "Coritas", 0) /* linha 3339 */
R(R_INTEIRA, "Kusaias", "Cusaías", 0) /* linha 3340 */
R(R_INTEIRA, "Lapidot", "Lapidote", 0) /* linha 3341 */
R(R_INTEIRA, "Maaseia", "Maaseias", 0) /* linha 3342 */
R(R_INTEIRA, "Mahalat", "Mahalate", 0) /* linha 3343 */
R(R_INTEIRA, "Mahalon", "Mahlon", 0) /* linha 3344 */
R(R_INTEIRA, "Manahat", "Manahate", 0) /* linha 3345 */
R(R_INTEIRA, "Maresha", "Maresa", 0) /* linha 3346 */
R(R_INTEIRA, "Masreka", "Masreca", 0) /* linha 3347 */
R(R_INTEIRA, "Mechona", "Mecona", 0) /* linha 3348 */
R(R_INTEIRA, "Melichu", "Melicu", 0) /* linha 3349 */
R(R_INTEIRA, "Meraias", "Meraías", 0) /* linha 3350 */
R(R_INTEIRA, "Meraiot", "Meraiote", 0) /* linha 3351 */
R(R_INTEIRA, "Meremot", "Meremote", 0) /* linha 3352 */
R(R_INTEIRA, "Meribah", "Meribá", 0) /* linha 3353 */
R(R_INTEIRA, "Mesobab", "Mesobabe", 0) /* linha 3354 */
R(R_INTEIRA, "Mesulum", "Mesulam", 0) /* linha 3355 */
R(R_INTEIRA, "Mezahab", "Mezahabe", 0) /* linha 3356 */
R(R_INTEIRA, "Michaia", "Micaia", 0) /* linha 3357 */
R(R_INTEIRA, "Micheas", "Miqueas", 0) /* linha 3358 */
R(R_INTEIRA, "Michmas", "Micmás", 0) /* linha 3359 */
R(R_INTEIRA, "Mihamin", "Miamim", 0) /* linha 3360 */
R(R_INTEIRA, "Miseria", "Miséria", 0) /* linha 3361 */
R(R_INTEIRA, "Moserot", "Moserote", 0) /* linha 3362 */
R(R_INTEIRA, "Nahalal", "Naalal", 0) /* linha 3363 */
R(R_INTEIRA, "Nahalol", "Naalol", 0) /* linha 3364 */
R(R_INTEIRA, "Naharai", "Naarai", 0) /* linha 3365 */
R(R_INTEIRA, "Naharat", "Naarate", 0) /* linha 3366 */
R(R_INTEIRA, "Napoles", "Nápoles", 0) /* linha 3367 */
R(R_INTEIRA, "Nebaiot", "Nebaiote", 0) /* linha 3368 */
R(R_INTEIRA, "Nebajot", "Nebaiote", 0) /* linha 3369 */
R(R_INTEIRA, "Nebalat", "Nebalate", 0) /* linha 3370 */
R(R_INTEIRA, "Neftoah", "Neftoa", 0) /* linha 3371 */
R(R_INTEIRA, "Nehusta", "Neusta", 0) /* linha 3372 */
R(R_INTEIRA, "Niniveh", "Nínive", 0) /* linha 3373 */
R(R_INTEIRA, "Nisroch", "Nisroque", 0) /* linha 3374 */
R(R_INTEIRA, "Olimpia", "Olímpia", 0) /* linha 3375 */
R(R_INTEIRA, "Onesimo", "Onésimo", 0) /* linha 3376 */
R(R_INTEIRA, "Pedaias", "Pedaías", 0) /* linha 3377 */
R(R_INTEIRA, "Pelaias", "Pelaías", 0) /* linha 3378 */
R(R_INTEIRA, "Pereseo", "Pereseu", 0) /* linha 3379 */
R(R_INTEIRA, "Pergamo", "Pérgamo", 0) /* linha 3380 */
R(R_INTEIRA, "Pibeset", "Pibesete", 0) /* linha 3381 */
R(R_INTEIRA, "Piraton", "Piratom", 0) /* linha 3382 */
R(R_INTEIRA, "Pisidia", "Pisídia", 0) /* linha 3383 */
R(R_INTEIRA, "Pozéste", "Puseste", 0) /* linha 3384 */
R(R_INTEIRA, "Queriot", "Queriote", 0) /* linha 3385 */
R(R_INTEIRA, "Rabsaké", "Rabsaqué", 0) /* linha 3386 */
R(R_INTEIRA, "Rafidim", "Refidim", 0) /* linha 3387 */
R(R_INTEIRA, "Refaias", "Refaías", 0) /* linha 3388 */
R(R_INTEIRA, "Rehobot", "Reobote", 0) /* linha 3389 */
R(R_INTEIRA, "Sachias", "Saquias", 0) /* linha 3390 */
R(R_INTEIRA, "Sadrach", "Sadraque", 0) /* linha 3391 */
R(R_INTEIRA, "Sahalim", "Saalim", 0) /* linha 3392 */
R(R_INTEIRA, "Sefarad", "Sefarade", 0) /* linha 3393 */
R(R_INTEIRA, "Selofad", "Selofade", 0) /* linha 3394 */
R(R_INTEIRA, "Selomit", "Selomite", 0) /* linha 3395 */
R(R_INTEIRA, "Selomot", "Selomote", 0) /* linha 3396 */
R(R_INTEIRA, "Semaias", "Semaías", 0) /* linha 3397 */
R(R_INTEIRA, "Seminit", "Seminite", 0) /* linha 3398 */
R(R_INTEIRA, "Seraias", "Seraías", 0) /* linha 3399 */
R(R_INTEIRA, "Sibolet", "Sibolete", 0) /* linha 3400 */
R(R_INTEIRA, "Soferet", "Soferete", 0) /* linha 3401 */
R(R_INTEIRA, "Taanach", "Taanaque", 0) /* linha 3402 */
R(R_INTEIRA, "Taberah", "Tabera", 0) /* linha 3403 */
R(R_INTEIRA, "Tertulo", "Tértulo", 0) /* linha 3404 */
R(R_INTEIRA, "Tichico", "Tíquico", 0) /* linha 3405 */
R(R_INTEIRA, "Tirhaká", "Tirhacá", 0) /* linha 3406 */
R(R_INTEIRA, "Trofimo", "Trófimo", 0) /* linha 3407 */
R(R_INTEIRA, "UFARSIN", "UFARSIM", 0) /* linha 3408 */
R(R_INTEIRA, "Zabulon", "Zebulom", 0) /* linha 3409 */
R(R_INTEIRA, "Zarefat", "Zarefate", 0) /* linha 3410 */
R(R_INTEIRA, "Zebulon", "Zebulom", 0) /* linha 3411 */
R(R_INTEIRA, "Zererat", "Zererate", 0) /* linha 3412 */
R(R_INTEIRA, "Zohelet", "Zohelete", 0) /* linha 3413 */
R(R_INTEIRA, "Abadon", "Abadom", 0) /* linha 3414 */
R(R_INTEIRA, "Abidah", "Abida", 0) /* linha 3415 */
R(R_INTEIRA, "Abihud", "Abihude", 0) /* linha 3416 */
R(R_INTEIRA, "Abisag", "Abisague", 0) /* linha 3417 */
R(R_INTEIRA, "Abitud", "Abitude", 0) /* linha 3418 */
R(R_INTEIRA, "Achaia", "Acaia", 0) /* linha 3419 */
R(R_INTEIRA, "Achbor", "Acbor", 0) /* linha 3420 */
R(R_INTEIRA, "Achsaf", "Acsafe", 0) /* linha 3421 */
R(R_INTEIRA, "Achzib", "Aczibe", 0) /* linha 3422 */
R(R_INTEIRA, "Adamah", "Adama", 0) /* linha 3423 */
R(R_INTEIRA, "Ahihud", "Ahihude", 0) /* linha 3424 */
R(R_INTEIRA, "Ahikam", "Ahicam", 0) /* linha 3425 */
R(R_INTEIRA, "Ahilud", "Ahilude", 0) /* linha 3426 */
R(R_INTEIRA, "Ahimot", "Ahimote", 0) /* linha 3427 */
R(R_INTEIRA, "Ahitub", "Ahitube", 0) /* linha 3428 */
R(R_INTEIRA, "Aialon", "Aijalom", 0) /* linha 3429 */
R(R_INTEIRA, "Ajalon", "Aijalom", 0) /* linha 3430 */
R(R_INTEIRA, "Alamet", "Alamete", 0) /* linha 3431 */
R(R_INTEIRA, "Alamot", "Alamote", 0) /* linha 3432 */
R(R_INTEIRA, "Alemet", "Alemete", 0) /* linha 3433 */
R(R_INTEIRA, "Amalek", "Amaleque", 0) /* linha 3434 */
R(R_INTEIRA, "Amelek", "Amaleque", 0) /* linha 3435 */
R(R_INTEIRA, "Anatot", "Anatote", 0) /* linha 3436 */
R(R_INTEIRA, "Arioch", "Arioque", 0) /* linha 3437 */
R(R_INTEIRA, "Arubot", "Arubote", 0) /* linha 3438 */
R(R_INTEIRA, "Asenat", "Asenate", 0) /* linha 3439 */
R(R_INTEIRA, "Atarot", "Atarote", 0) /* linha 3440 */
R(R_INTEIRA, "Baalat", "Baalate", 0) /* linha 3441 */
R(R_INTEIRA, "Baalin", "Baalim", 0) /* linha 3442 */
R(R_INTEIRA, "Bakbuk", "Bacbuque", 0) /* linha 3443 */
R(R_INTEIRA, "Bariah", "Baria", 0) /* linha 3444 */
R(R_INTEIRA, "Baslit", "Baslite", 0) /* linha 3445 */
R(R_INTEIRA, "Baslut", "Baslute", 0) /* linha 3446 */
R(R_INTEIRA, "Basmat", "Basemate", 0) /* linha 3447 */
R(R_INTEIRA, "Bealot", "Bealote", 0) /* linha 3448 */
R(R_INTEIRA, "Bearot", "Bearote", 0) /* linha 3449 */
R(R_INTEIRA, "Becher", "Bequer", 0) /* linha 3450 */
R(R_INTEIRA, "Beerot", "Beerote", 0) /* linha 3451 */
R(R_INTEIRA, "Beriah", "Beria", 0) /* linha 3452 */
R(R_INTEIRA, "Berish", "Beris", 0) /* linha 3453 */
R(R_INTEIRA, "Bet-el", "Betel", 0) /* linha 3454 */
R(R_INTEIRA, "Betzur", "Bet-zur", 0) /* linha 3455 */
R(R_INTEIRA, "Bichri", "Bicri", 0) /* linha 3456 */
R(R_INTEIRA, "Bidkar", "Bidcar", 0) /* linha 3457 */
R(R_INTEIRA, "Bildad", "Bildade", 0) /* linha 3458 */
R(R_INTEIRA, "Bilhah", "Bilha", 0) /* linha 3459 */
R(R_INTEIRA, "Bochim", "Boquim", 0) /* linha 3460 */
R(R_INTEIRA, "Boscat", "Boscate", 0) /* linha 3461 */
R(R_INTEIRA, "Boskat", "Boscate", 0) /* linha 3462 */
R(R_INTEIRA, "Bosrah", "Bosra", 0) /* linha 3463 */
R(R_INTEIRA, "Calneh", "Calne", 0) /* linha 3464 */
R(R_INTEIRA, "Carmel", "Carmelo", 0) /* linha 3465 */
R(R_INTEIRA, "Chamoz", "Camos", 0) /* linha 3466 */
R(R_INTEIRA, "Chebar", "Quebar", 0) /* linha 3467 */
R(R_INTEIRA, "Chelal", "Quelal", 0) /* linha 3468 */
R(R_INTEIRA, "Chelba", "Quelba", 0) /* linha 3469 */
R(R_INTEIRA, "Chelub", "Quelube", 0) /* linha 3470 */
R(R_INTEIRA, "Cheran", "Queran", 0) /* linha 3471 */
R(R_INTEIRA, "Cheret", "Querete", 0) /* linha 3472 */
R(R_INTEIRA, "Cherub", "Querube", 0) /* linha 3473 */
R(R_INTEIRA, "Chesed", "Quesede", 0) /* linha 3474 */
R(R_INTEIRA, "Chesil", "Quesil", 0) /* linha 3475 */
R(R_INTEIRA, "Chezib", "Quezibe", 0) /* linha 3476 */
R(R_INTEIRA, "Chidon", "Quidon", 0) /* linha 3477 */
R(R_INTEIRA, "Cholon", "Colon", 0) /* linha 3478 */
R(R_INTEIRA, "Darkon", "Darcon", 0) /* linha 3479 */
R(R_INTEIRA, "Debora", "Débora", 0) /* linha 3480 */
R(R_INTEIRA, "Diblat", "Diblate", 0) /* linha 3481 */
R(R_INTEIRA, "Diclah", "Dicla", 0) /* linha 3482 */
R(R_INTEIRA, "Didimo", "Dídimo", 0) /* linha 3483 */
R(R_INTEIRA, "Dishan", "Disan", 0) /* linha 3484 */
R(R_INTEIRA, "Dishon", "Dison", 0) /* linha 3485 */
R(R_INTEIRA, "Dobrat", "Dobrate", 0) /* linha 3486 */
R(R_INTEIRA, "Eisque", "Eis que", 0) /* linha 3487 */
R(R_INTEIRA, "Elidad", "Elidade", 0) /* linha 3488 */
R(R_INTEIRA, "Elifsz", "Elifaz", 0) /* linha 3489 */
R(R_INTEIRA, "Elkana", "Elcana", 0) /* linha 3490 */
R(R_INTEIRA, "Elteke", "Elteque", 0) /* linha 3491 */
R(R_INTEIRA, "Eshban", "Esban", 0) /* linha 3492 */
R(R_INTEIRA, "Estmoa", "Estemoa", 0) /* linha 3493 */
R(R_INTEIRA, "Evodia", "Evódia", 0) /* linha 3494 */
R(R_INTEIRA, "Fichol", "Ficol", 0) /* linha 3495 */
R(R_INTEIRA, "Finéas", "Fineas", 0) /* linha 3496 */
R(R_INTEIRA, "Galaad", "Gileade", 0) /* linha 3497 */
R(R_INTEIRA, "Galeed", "Galeede", 0) /* linha 3498 */
R(R_INTEIRA, "Gibeah", "Gibea", 0) /* linha 3499 */
R(R_INTEIRA, "Gilead", "Gileade", 0) /* linha 3500 */
R(R_INTEIRA, "Goliat", "Golias", 0) /* linha 3501 */
R(R_INTEIRA, "Goshen", "Gósen", 0) /* linha 3502 */
R(R_INTEIRA, "Gudgod", "Gudgode", 0) /* linha 3503 */
R(R_INTEIRA, "Hakkos", "Hacos", 0) /* linha 3504 */
R(R_INTEIRA, "Hakufa", "Hacufa", 0) /* linha 3505 */
R(R_INTEIRA, "Hanoch", "Hanoque", 0) /* linha 3506 */
R(R_INTEIRA, "Hassub", "Hassube", 0) /* linha 3507 */
R(R_INTEIRA, "Hatach", "Hataque", 0) /* linha 3508 */
R(R_INTEIRA, "Havvim", "Havim", 0) /* linha 3509 */
R(R_INTEIRA, "Helkai", "Helcai", 0) /* linha 3510 */
R(R_INTEIRA, "Helkat", "Helcat", 0) /* linha 3511 */
R(R_INTEIRA, "Iarmut", "Jarmut", 0) /* linha 3512 */
R(R_INTEIRA, "Icabod", "Icabode", 0) /* linha 3513 */
R(R_INTEIRA, "Idumea", "Idumeia", 0) /* linha 3514 */
R(R_INTEIRA, "Jaakan", "Jaacan", 0) /* linha 3515 */
R(R_INTEIRA, "Jachan", "Jacan", 0) /* linha 3516 */
R(R_INTEIRA, "Jachin", "Jaquin", 0) /* linha 3517 */
R(R_INTEIRA, "Janoah", "Janoa", 0) /* linha 3518 */
R(R_INTEIRA, "Jaroah", "Jaroa", 0) /* linha 3519 */
R(R_INTEIRA, "Jefone", "Jefoné", 0) /* linha 3520 */
R(R_INTEIRA, "Jeriot", "Jeriote", 0) /* linha 3521 */
R(R_INTEIRA, "Jisbac", "Jisbaque", 0) /* linha 3522 */
R(R_INTEIRA, "Jisbak", "Jisbaque", 0) /* linha 3523 */
R(R_INTEIRA, "Johana", "Joana", 0) /* linha 3524 */
R(R_INTEIRA, "Joksan", "Jocsan", 0) /* linha 3525 */
R(R_INTEIRA, "Joktan", "Joctan", 0) /* linha 3526 */
R(R_INTEIRA, "Jotbat", "Jotbate", 0) /* linha 3527 */
R(R_INTEIRA, "Juchal", "Jucal", 0) /* linha 3528 */
R(R_INTEIRA, "JUDEOS", "JUDEUS", 0) /* linha 3529 */
R(R_INTEIRA, "Kareat", "Careate", 0) /* linha 3530 */
R(R_INTEIRA, "Kedmot", "Quedmote", 0) /* linha 3531 */
R(R_INTEIRA, "Kelita", "Quelita", 0) /* linha 3532 */
R(R_INTEIRA, "Kemuel", "Quemuel", 0) /* linha 3533 */
R(R_INTEIRA, "Keriot", "Queriote", 0) /* linha 3534 */
R(R_INTEIRA, "Ketura", "Quetura", 0) /* linha 3535 */
R(R_INTEIRA, "Kilmad", "Quilmade", 0) /* linha 3536 */
R(R_INTEIRA, "Kiriat", "Quiriate", 0) /* linha 3537 */
R(R_INTEIRA, "Kision", "Quision", 0) /* linha 3538 */
R(R_INTEIRA, "Kisjon", "Quision", 0) /* linha 3539 */
R(R_INTEIRA, "Kitron", "Quitron", 0) /* linha 3540 */
R(R_INTEIRA, "Lachis", "Laquis", 0) /* linha 3541 */
R(R_INTEIRA, "Lebaot", "Lebaote", 0) /* linha 3542 */
R(R_INTEIRA, "Lisias", "Lísias", 0) /* linha 3543 */
R(R_INTEIRA, "Maacah", "Maaca", 0) /* linha 3544 */
R(R_INTEIRA, "Maacat", "Maacate", 0) /* linha 3545 */
R(R_INTEIRA, "Maacha", "Maaca", 0) /* linha 3546 */
R(R_INTEIRA, "Maarat", "Maarate", 0) /* linha 3547 */
R(R_INTEIRA, "Machir", "Maquir", 0) /* linha 3548 */
R(R_INTEIRA, "Machla", "Macla", 0) /* linha 3549 */
R(R_INTEIRA, "Machli", "Maheli", 0) /* linha 3550 */
R(R_INTEIRA, "Mahali", "Maheli", 0) /* linha 3551 */
R(R_INTEIRA, "Makeda", "Maqueda", 0) /* linha 3552 */
R(R_INTEIRA, "Maluch", "Maluque", 0) /* linha 3553 */
R(R_INTEIRA, "Mashit", "Mashite", 0) /* linha 3554 */
R(R_INTEIRA, "Massah", "Massá", 0) /* linha 3555 */
R(R_INTEIRA, "Matred", "Matrede", 0) /* linha 3556 */
R(R_INTEIRA, "Mefaat", "Mefaate", 0) /* linha 3557 */
R(R_INTEIRA, "Melchi", "Melqui", 0) /* linha 3558 */
R(R_INTEIRA, "Melech", "Meleque", 0) /* linha 3559 */
R(R_INTEIRA, "Memfis", "Mênfis", 0) /* linha 3560 */
R(R_INTEIRA, "Mesach", "Mesaque", 0) /* linha 3561 */
R(R_INTEIRA, "Mesech", "Meseque", 0) /* linha 3562 */
R(R_INTEIRA, "Michal", "Mical", 0) /* linha 3563 */
R(R_INTEIRA, "Michri", "Micri", 0) /* linha 3564 */
R(R_INTEIRA, "Micmas", "Micmás", 0) /* linha 3565 */
R(R_INTEIRA, "Midian", "Midiã", 0) /* linha 3566 */
R(R_INTEIRA, "Mifkad", "Mifcade", 0) /* linha 3567 */
R(R_INTEIRA, "Migron", "Migrom", 0) /* linha 3568 */
R(R_INTEIRA, "Miklot", "Miclote", 0) /* linha 3569 */
R(R_INTEIRA, "Milcah", "Milca", 0) /* linha 3570 */
R(R_INTEIRA, "Milkom", "Milcom", 0) /* linha 3571 */
R(R_INTEIRA, "Misgab", "Misgabe", 0) /* linha 3572 */
R(R_INTEIRA, "Mispah", "Mispa", 0) /* linha 3573 */
R(R_INTEIRA, "Mispeh", "Mispe", 0) /* linha 3574 */
R(R_INTEIRA, "Mizpah", "Mispa", 0) /* linha 3575 */
R(R_INTEIRA, "Mizzah", "Miza", 0) /* linha 3576 */
R(R_INTEIRA, "Mnason", "Mnasom", 0) /* linha 3577 */
R(R_INTEIRA, "Molech", "Moloque", 0) /* linha 3578 */
R(R_INTEIRA, "Moloch", "Moloque", 0) /* linha 3579 */
R(R_INTEIRA, "Naaman", "Naamã", 0) /* linha 3580 */
R(R_INTEIRA, "Naaran", "Naarã", 0) /* linha 3581 */
R(R_INTEIRA, "Naason", "Naassom", 0) /* linha 3582 */
R(R_INTEIRA, "Nachon", "Nacom", 0) /* linha 3583 */
R(R_INTEIRA, "Nachor", "Naor", 0) /* linha 3584 */
R(R_INTEIRA, "Nekoda", "Necoda", 0) /* linha 3585 */
R(R_INTEIRA, "Nemrod", "Ninrode", 0) /* linha 3586 */
R(R_INTEIRA, "Nesiag", "Nesiague", 0) /* linha 3587 */
R(R_INTEIRA, "Nesiah", "Nesia", 0) /* linha 3588 */
R(R_INTEIRA, "Nibsan", "Nibsã", 0) /* linha 3589 */
R(R_INTEIRA, "Nimrod", "Ninrode", 0) /* linha 3590 */
R(R_INTEIRA, "Ninive", "Nínive", 0) /* linha 3591 */
R(R_INTEIRA, "Ochran", "Ocrã", 0) /* linha 3592 */
R(R_INTEIRA, "Orfãos", "Órfãos", 0) /* linha 3593 */
R(R_INTEIRA, "Parnah", "Parna", 0) /* linha 3594 */
R(R_INTEIRA, "Paruah", "Parua", 0) /* linha 3595 */
R(R_INTEIRA, "Pasach", "Pasaque", 0) /* linha 3596 */
R(R_INTEIRA, "Paseah", "Pasea", 0) /* linha 3597 */
R(R_INTEIRA, "Pashur", "Pasur", 0) /* linha 3598 */
R(R_INTEIRA, "Pekaia", "Pecaia", 0) /* linha 3599 */
R(R_INTEIRA, "Peseah", "Pesea", 0) /* linha 3600 */
R(R_INTEIRA, "Pôe-na", "Põe-na", 0) /* linha 3601 */
R(R_INTEIRA, "Porcio", "Pórcio", 0) /* linha 3602 */
R(R_INTEIRA, "Publio", "Públio", 0) /* linha 3603 */
R(R_INTEIRA, "Quenat", "Quenate", 0) /* linha 3604 */
R(R_INTEIRA, "Raamah", "Raama", 0) /* linha 3605 */
R(R_INTEIRA, "Rachal", "Racal", 0) /* linha 3606 */
R(R_INTEIRA, "Rachel", "Raquel", 0) /* linha 3607 */
R(R_INTEIRA, "Reaias", "Reaías", 0) /* linha 3608 */
R(R_INTEIRA, "Rechab", "Recabe", 0) /* linha 3609 */
R(R_INTEIRA, "Rechob", "Recobe", 0) /* linha 3610 */
R(R_INTEIRA, "Rehuel", "Reuel", 0) /* linha 3611 */
R(R_INTEIRA, "Remfan", "Renfã", 0) /* linha 3612 */
R(R_INTEIRA, "Rhegio", "Régio", 0) /* linha 3613 */
R(R_INTEIRA, "Rhehum", "Reum", 0) /* linha 3614 */
R(R_INTEIRA, "Rhodes", "Rodes", 0) /* linha 3615 */
R(R_INTEIRA, "Rohega", "Roega", 0) /* linha 3616 */
R(R_INTEIRA, "Ruhama", "Ruama", 0) /* linha 3617 */
R(R_INTEIRA, "Sabtah", "Sabta", 0) /* linha 3618 */
R(R_INTEIRA, "Salcha", "Salca", 0) /* linha 3619 */
R(R_INTEIRA, "Samhut", "Samhute", 0) /* linha 3620 */
R(R_INTEIRA, "Samlah", "Samla", 0) /* linha 3621 */
R(R_INTEIRA, "Sargon", "Sargom", 0) /* linha 3622 */
R(R_INTEIRA, "Saruch", "Saruque", 0) /* linha 3623 */
R(R_INTEIRA, "Scheba", "Sheba", 0) /* linha 3624 */
R(R_INTEIRA, "Sechem", "Sequém", 0) /* linha 3625 */
R(R_INTEIRA, "Sechen", "Sequém", 0) /* linha 3626 */
R(R_INTEIRA, "Seirat", "Seirate", 0) /* linha 3627 */
R(R_INTEIRA, "Semaia", "Semaía", 0) /* linha 3628 */
R(R_INTEIRA, "Sesach", "Sesaque", 0) /* linha 3629 */
R(R_INTEIRA, "Shalum", "Salum", 0) /* linha 3630 */
R(R_INTEIRA, "Shelah", "Selá", 0) /* linha 3631 */
R(R_INTEIRA, "Shelef", "Selefe", 0) /* linha 3632 */
R(R_INTEIRA, "Shilem", "Silem", 0) /* linha 3633 */
R(R_INTEIRA, "Shiloh", "Siló", 0) /* linha 3634 */
R(R_INTEIRA, "Shinab", "Shinabe", 0) /* linha 3635 */
R(R_INTEIRA, "Shinar", "Sinear", 0) /* linha 3636 */
R(R_INTEIRA, "Shobab", "Sobabe", 0) /* linha 3637 */
R(R_INTEIRA, "Shobal", "Sobal", 0) /* linha 3638 */
R(R_INTEIRA, "Sichem", "Siquém", 0) /* linha 3639 */
R(R_INTEIRA, "Sichor", "Sicor", 0) /* linha 3640 */
R(R_INTEIRA, "Sicron", "Sicrom", 0) /* linha 3641 */
R(R_INTEIRA, "Sifmot", "Sifmote", 0) /* linha 3642 */
R(R_INTEIRA, "Siklag", "Siclag", 0) /* linha 3643 */
R(R_INTEIRA, "Silchi", "Silqui", 0) /* linha 3644 */
R(R_INTEIRA, "Simeat", "Simeate", 0) /* linha 3645 */
R(R_INTEIRA, "Simeon", "Simeão", 0) /* linha 3646 */
R(R_INTEIRA, "Simrat", "Simrate", 0) /* linha 3647 */
R(R_INTEIRA, "Simret", "Simrete", 0) /* linha 3648 */
R(R_INTEIRA, "Simron", "Simrom", 0) /* linha 3649 */
R(R_INTEIRA, "Sirion", "Siriom", 0) /* linha 3650 */
R(R_INTEIRA, "Sisera", "Sísera", 0) /* linha 3651 */
R(R_INTEIRA, "Smirna", "Esmirna", 0) /* linha 3652 */
R(R_INTEIRA, "Sobach", "Sobaque", 0) /* linha 3653 */
R(R_INTEIRA, "Taanak", "Taanaque", 0) /* linha 3654 */
R(R_INTEIRA, "Tabaot", "Tabaote", 0) /* linha 3655 */
R(R_INTEIRA, "Tachat", "Taquate", 0) /* linha 3656 */
R(R_INTEIRA, "Talmon", "Talmom", 0) /* linha 3657 */
R(R_INTEIRA, "Tanach", "Tanaque", 0) /* linha 3658 */
R(R_INTEIRA, "Tartak", "Tartaque", 0) /* linha 3659 */
R(R_INTEIRA, "Tibhat", "Tibhate", 0) /* linha 3660 */
R(R_INTEIRA, "Timnah", "Timna", 0) /* linha 3661 */
R(R_INTEIRA, "Timnat", "Timnate", 0) /* linha 3662 */
R(R_INTEIRA, "Tochen", "Toquen", 0) /* linha 3663 */
R(R_INTEIRA, "Tokhat", "Tocate", 0) /* linha 3664 */
R(R_INTEIRA, "Ussiel", "Uziel", 0) /* linha 3665 */
R(R_INTEIRA, "Uzziel", "Uziel", 0) /* linha 3666 */
R(R_INTEIRA, "Zachur", "Zacur", 0) /* linha 3667 */
R(R_INTEIRA, "Zalmon", "Zalmom", 0) /* linha 3668 */
R(R_INTEIRA, "Zarchi", "Zarqui", 0) /* linha 3669 */
R(R_INTEIRA, "Zecher", "Zequer", 0) /* linha 3670 */
R(R_INTEIRA, "Zibeon", "Zibeom", 0) /* linha 3671 */
R(R_INTEIRA, "Zichri", "Zicri", 0) /* linha 3672 */
R(R_INTEIRA, "Zifion", "Zifiom", 0) /* linha 3673 */
R(R_INTEIRA, "Zifron", "Zifrom", 0) /* linha 3674 */
R(R_INTEIRA, "Ziklag", "Siclag", 0) /* linha 3675 */
R(R_INTEIRA, "Zilpah", "Zilpa", 0) /* linha 3676 */
R(R_INTEIRA, "Zipora", "Zípora", 0) /* linha 3677 */
R(R_INTEIRA, "Achab", "Acabe", 0) /* linha 3678 */
R(R_INTEIRA, "Achor", "Acor", 0) /* linha 3679 */
R(R_INTEIRA, "Acsaf", "Acsafe", 0) /* linha 3680 */
R(R_INTEIRA, "Aczib", "Aczibe", 0) /* linha 3681 */
R(R_INTEIRA, "Admah", "Adma", 0) /* linha 3682 */
R(R_INTEIRA, "Adnah", "Adna", 0) /* linha 3683 */
R(R_INTEIRA, "Afeka", "Afeca", 0) /* linha 3684 */
R(R_INTEIRA, "Ahoah", "Ahoa", 0) /* linha 3685 */
R(R_INTEIRA, "Ahrah", "Ahra", 0) /* linha 3686 */
R(R_INTEIRA, "Akkub", "Acube", 0) /* linha 3687 */
R(R_INTEIRA, "Alfeo", "Alfeu", 0) /* linha 3688 */
R(R_INTEIRA, "Almon", "Almom", 0) /* linha 3689 */
R(R_INTEIRA, "Amnon", "Amnom", 0) /* linha 3690 */
R(R_INTEIRA, "Apfia", "Afia", 0) /* linha 3691 */
R(R_INTEIRA, "Ardon", "Ardom", 0) /* linha 3692 */
R(R_INTEIRA, "Arfad", "Arpade", 0) /* linha 3693 */
R(R_INTEIRA, "Argob", "Argobe", 0) /* linha 3694 */
R(R_INTEIRA, "Arieh", "Arie", 0) /* linha 3695 */
R(R_INTEIRA, "Arkeu", "Arqueu", 0) /* linha 3696 */
R(R_INTEIRA, "Arnon", "Arnom", 0) /* linha 3697 */
R(R_INTEIRA, "Arpad", "Arpade", 0) /* linha 3698 */
R(R_INTEIRA, "Arvad", "Arvade", 0) /* linha 3699 */
R(R_INTEIRA, "Asdod", "Asdode", 0) /* linha 3700 */
R(R_INTEIRA, "Aserá", "Asera", 0) /* linha 3701 */
R(R_INTEIRA, "Asgad", "Azgade", 0) /* linha 3702 */
R(R_INTEIRA, "Asher", "Aser", 0) /* linha 3703 */
R(R_INTEIRA, "Ashur", "Asur", 0) /* linha 3704 */
R(R_INTEIRA, "Asmon", "Azmom", 0) /* linha 3705 */
R(R_INTEIRA, "Assás", "Assaz", 0) /* linha 3706 */
R(R_INTEIRA, "Asson", "Assom", 0) /* linha 3707 */
R(R_INTEIRA, "Asvat", "Asvate", 0) /* linha 3708 */
R(R_INTEIRA, "Atrot", "Atrote", 0) /* linha 3709 */
R(R_INTEIRA, "Azaka", "Azeca", 0) /* linha 3710 */
R(R_INTEIRA, "Azbuk", "Azbuque", 0) /* linha 3711 */
R(R_INTEIRA, "Azeka", "Azeca", 0) /* linha 3712 */
R(R_INTEIRA, "Azgad", "Azgade", 0) /* linha 3713 */
R(R_INTEIRA, "Azmon", "Azmom", 0) /* linha 3714 */
R(R_INTEIRA, "Baása", "Baasa", 0) /* linha 3715 */
R(R_INTEIRA, "Baiit", "Baiite", 0) /* linha 3716 */
R(R_INTEIRA, "Balac", "Balaque", 0) /* linha 3717 */
R(R_INTEIRA, "Balak", "Balaque", 0) /* linha 3718 */
R(R_INTEIRA, "Bamah", "Bama", 0) /* linha 3719 */
R(R_INTEIRA, "Bamot", "Bamote", 0) /* linha 3720 */
R(R_INTEIRA, "Barac", "Baraque", 0) /* linha 3721 */
R(R_INTEIRA, "Bedad", "Bedade", 0) /* linha 3722 */
R(R_INTEIRA, "Behon", "Behom", 0) /* linha 3723 */
R(R_INTEIRA, "Belah", "Bela", 0) /* linha 3724 */
R(R_INTEIRA, "Bered", "Berede", 0) /* linha 3725 */
R(R_INTEIRA, "Berit", "Berite", 0) /* linha 3726 */
R(R_INTEIRA, "Bezek", "Bezeque", 0) /* linha 3727 */
R(R_INTEIRA, "Bukki", "Buqui", 0) /* linha 3728 */
R(R_INTEIRA, "Caleb", "Calebe", 0) /* linha 3729 */
R(R_INTEIRA, "Carit", "Carite", 0) /* linha 3730 */
R(R_INTEIRA, "Catat", "Catate", 0) /* linha 3731 */
R(R_INTEIRA, "Chloe", "Cloé", 0) /* linha 3732 */
R(R_INTEIRA, "Chuza", "Cuza", 0) /* linha 3733 */
R(R_INTEIRA, "Dalet", "Dalete", 0) /* linha 3734 */
R(R_INTEIRA, "Démas", "Demas", 0) /* linha 3735 */
R(R_INTEIRA, "Dikla", "Dicla", 0) /* linha 3736 */
R(R_INTEIRA, "Dinah", "Diná", 0) /* linha 3737 */
R(R_INTEIRA, "Dofka", "Dofca", 0) /* linha 3738 */
R(R_INTEIRA, "Efrat", "Efrate", 0) /* linha 3739 */
R(R_INTEIRA, "Ekron", "Ecron", 0) /* linha 3740 */
R(R_INTEIRA, "Eldad", "Eldade", 0) /* linha 3741 */
R(R_INTEIRA, "Eldah", "Elda", 0) /* linha 3742 */
R(R_INTEIRA, "Elead", "Eleade", 0) /* linha 3743 */
R(R_INTEIRA, "Eliab", "Eliabe", 0) /* linha 3744 */
R(R_INTEIRA, "Eliad", "Eliade", 0) /* linha 3745 */
R(R_INTEIRA, "Elika", "Elica", 0) /* linha 3746 */
R(R_INTEIRA, "Emaus", "Emaús", 0) /* linha 3747 */
R(R_INTEIRA, "Eneas", "Eneias", 0) /* linha 3748 */
R(R_INTEIRA, "Erech", "Ereque", 0) /* linha 3749 */
R(R_INTEIRA, "Galio", "Gálio", 0) /* linha 3750 */
R(R_INTEIRA, "Gareb", "Garebe", 0) /* linha 3751 */
R(R_INTEIRA, "Gazer", "Gezer", 0) /* linha 3752 */
R(R_INTEIRA, "Geser", "Gezer", 0) /* linha 3753 */
R(R_INTEIRA, "Golan", "Golã", 0) /* linha 3754 */
R(R_INTEIRA, "Gosen", "Gósen", 0) /* linha 3755 */
R(R_INTEIRA, "Hacub", "Hacube", 0) /* linha 3756 */
R(R_INTEIRA, "Hadad", "Hadade", 0) /* linha 3757 */
R(R_INTEIRA, "Hadid", "Hadide", 0) /* linha 3758 */
R(R_INTEIRA, "Hagab", "Hagabe", 0) /* linha 3759 */
R(R_INTEIRA, "Halah", "Hala", 0) /* linha 3760 */
R(R_INTEIRA, "Harad", "Harade", 0) /* linha 3761 */
R(R_INTEIRA, "Harod", "Harode", 0) /* linha 3762 */
R(R_INTEIRA, "Hasub", "Hassube", 0) /* linha 3763 */
R(R_INTEIRA, "Heleb", "Helebe", 0) /* linha 3764 */
R(R_INTEIRA, "Heled", "Helede", 0) /* linha 3765 */
R(R_INTEIRA, "Helek", "Heleque", 0) /* linha 3766 */
R(R_INTEIRA, "Hirah", "Hira", 0) /* linha 3767 */
R(R_INTEIRA, "Hobab", "Hobabe", 0) /* linha 3768 */
R(R_INTEIRA, "Hobah", "Hoba", 0) /* linha 3769 */
R(R_INTEIRA, "Hucok", "Hucoque", 0) /* linha 3770 */
R(R_INTEIRA, "Hukok", "Hucoque", 0) /* linha 3771 */
R(R_INTEIRA, "Iftah", "Ifta", 0) /* linha 3772 */
R(R_INTEIRA, "Ikkes", "Iques", 0) /* linha 3773 */
R(R_INTEIRA, "Imnah", "Imna", 0) /* linha 3774 */
R(R_INTEIRA, "India", "Índia", 0) /* linha 3775 */
R(R_INTEIRA, "Isbah", "Isba", 0) /* linha 3776 */
R(R_INTEIRA, "Iscah", "Isca", 0) /* linha 3777 */
R(R_INTEIRA, "Ishod", "Ishode", 0) /* linha 3778 */
R(R_INTEIRA, "Isrel", "Israel", 0) /* linha 3779 */
R(R_INTEIRA, "Jabok", "Jaboque", 0) /* linha 3780 */
R(R_INTEIRA, "Jafet", "Jafé", 0) /* linha 3781 */
R(R_INTEIRA, "Jahas", "Jahaz", 0) /* linha 3782 */
R(R_INTEIRA, "Jakim", "Jaquim", 0) /* linha 3783 */
R(R_INTEIRA, "Jarah", "Jara", 0) /* linha 3784 */
R(R_INTEIRA, "Jareb", "Jarebe", 0) /* linha 3785 */
R(R_INTEIRA, "Jarib", "Jaribe", 0) /* linha 3786 */
R(R_INTEIRA, "Jasib", "Jasibe", 0) /* linha 3787 */
R(R_INTEIRA, "Jasub", "Jasube", 0) /* linha 3788 */
R(R_INTEIRA, "Jehud", "Jehude", 0) /* linha 3789 */
R(R_INTEIRA, "Jerah", "Jerá", 0) /* linha 3790 */
R(R_INTEIRA, "Jered", "Jerede", 0) /* linha 3791 */
R(R_INTEIRA, "Jesse", "Jessé", 0) /* linha 3792 */
R(R_INTEIRA, "Jetet", "Jetete", 0) /* linha 3793 */
R(R_INTEIRA, "Jeush", "Jeús", 0) /* linha 3794 */
R(R_INTEIRA, "Jobab", "Jobabe", 0) /* linha 3795 */
R(R_INTEIRA, "Johat", "Johate", 0) /* linha 3796 */
R(R_INTEIRA, "Jokim", "Joquim", 0) /* linha 3797 */
R(R_INTEIRA, "Judit", "Judite", 0) /* linha 3798 */
R(R_INTEIRA, "Julia", "Júlia", 0) /* linha 3799 */
R(R_INTEIRA, "Junia", "Júnia", 0) /* linha 3800 */
R(R_INTEIRA, "Kades", "Cades", 0) /* linha 3801 */
R(R_INTEIRA, "Kalai", "Calai", 0) /* linha 3802 */
R(R_INTEIRA, "Katan", "Catan", 0) /* linha 3803 */
R(R_INTEIRA, "Kedar", "Quedar", 0) /* linha 3804 */
R(R_INTEIRA, "Kedes", "Quedes", 0) /* linha 3805 */
R(R_INTEIRA, "Kedma", "Quedma", 0) /* linha 3806 */
R(R_INTEIRA, "Keila", "Queila", 0) /* linha 3807 */
R(R_INTEIRA, "Kenas", "Quenaz", 0) /* linha 3808 */
R(R_INTEIRA, "Kenat", "Quenate", 0) /* linha 3809 */
R(R_INTEIRA, "Kenaz", "Quenaz", 0) /* linha 3810 */
R(R_INTEIRA, "Kenez", "Quenaz", 0) /* linha 3811 */
R(R_INTEIRA, "Keros", "Queros", 0) /* linha 3812 */
R(R_INTEIRA, "Kison", "Quison", 0) /* linha 3813 */
R(R_INTEIRA, "Kitim", "Quitim", 0) /* linha 3814 */
R(R_INTEIRA, "Kohat", "Coate", 0) /* linha 3815 */
R(R_INTEIRA, "Korah", "Corá", 0) /* linha 3816 */
R(R_INTEIRA, "Lahad", "Lahade", 0) /* linha 3817 */
R(R_INTEIRA, "Lakum", "Lacum", 0) /* linha 3818 */
R(R_INTEIRA, "Lebeo", "Lebeu", 0) /* linha 3819 */
R(R_INTEIRA, "Lecha", "Leca", 0) /* linha 3820 */
R(R_INTEIRA, "Lechi", "Lequi", 0) /* linha 3821 */
R(R_INTEIRA, "Lidia", "Lídia", 0) /* linha 3822 */
R(R_INTEIRA, "Likhi", "Liqui", 0) /* linha 3823 */
R(R_INTEIRA, "Lucio", "Lúcio", 0) /* linha 3824 */
R(R_INTEIRA, "Luhit", "Luhite", 0) /* linha 3825 */
R(R_INTEIRA, "Maaka", "Maaca", 0) /* linha 3826 */
R(R_INTEIRA, "Machi", "Maqui", 0) /* linha 3827 */
R(R_INTEIRA, "Mahat", "Mahate", 0) /* linha 3828 */
R(R_INTEIRA, "Mahon", "Mahlon", 0) /* linha 3829 */
R(R_INTEIRA, "Makas", "Macas", 0) /* linha 3830 */
R(R_INTEIRA, "Maoch", "Maoque", 0) /* linha 3831 */
R(R_INTEIRA, "Marah", "Mara", 0) /* linha 3832 */
R(R_INTEIRA, "Marot", "Marote", 0) /* linha 3833 */
R(R_INTEIRA, "Matãa", "Matana", 0) /* linha 3834 */
R(R_INTEIRA, "Medad", "Medade", 0) /* linha 3835 */
R(R_INTEIRA, "Merab", "Merabe", 0) /* linha 3836 */
R(R_INTEIRA, "Mered", "Merede", 0) /* linha 3837 */
R(R_INTEIRA, "Micah", "Mica", 0) /* linha 3838 */
R(R_INTEIRA, "Midin", "Midim", 0) /* linha 3839 */
R(R_INTEIRA, "Milka", "Milca", 0) /* linha 3840 */
R(R_INTEIRA, "Minit", "Minite", 0) /* linha 3841 */
R(R_INTEIRA, "Mitka", "Mitca", 0) /* linha 3842 */
R(R_INTEIRA, "Molid", "Molide", 0) /* linha 3843 */
R(R_INTEIRA, "Nabot", "Nabote", 0) /* linha 3844 */
R(R_INTEIRA, "Nadab", "Nadabe", 0) /* linha 3845 */
R(R_INTEIRA, "Nahas", "Naás", 0) /* linha 3846 */
R(R_INTEIRA, "Nahat", "Naate", 0) /* linha 3847 */
R(R_INTEIRA, "Nahor", "Naor", 0) /* linha 3848 */
R(R_INTEIRA, "Nahum", "Naum", 0) /* linha 3849 */
R(R_INTEIRA, "Naiot", "Naiote", 0) /* linha 3850 */
R(R_INTEIRA, "Nebat", "Nebate", 0) /* linha 3851 */
R(R_INTEIRA, "Necho", "Neco", 0) /* linha 3852 */
R(R_INTEIRA, "Nefeg", "Nefegue", 0) /* linha 3853 */
R(R_INTEIRA, "Nehum", "Neum", 0) /* linha 3854 */
R(R_INTEIRA, "Nekeb", "Nequebe", 0) /* linha 3855 */
R(R_INTEIRA, "Netan", "Netã", 0) /* linha 3856 */
R(R_INTEIRA, "Nezib", "Nezibe", 0) /* linha 3857 */
R(R_INTEIRA, "Nimfa", "Ninfa", 0) /* linha 3858 */
R(R_INTEIRA, "Nobah", "Noba", 0) /* linha 3859 */
R(R_INTEIRA, "Nodab", "Nodabe", 0) /* linha 3860 */
R(R_INTEIRA, "Nofah", "Nofa", 0) /* linha 3861 */
R(R_INTEIRA, "Nogah", "Noga", 0) /* linha 3862 */
R(R_INTEIRA, "Nogat", "Nogate", 0) /* linha 3863 */
R(R_INTEIRA, "Ornan", "Ornã", 0) /* linha 3864 */
R(R_INTEIRA, "Padan", "Padã", 0) /* linha 3865 */
R(R_INTEIRA, "Padon", "Padom", 0) /* linha 3866 */
R(R_INTEIRA, "Paran", "Parã", 0) /* linha 3867 */
R(R_INTEIRA, "Pecod", "Pecode", 0) /* linha 3868 */
R(R_INTEIRA, "Peleg", "Pelegue", 0) /* linha 3869 */
R(R_INTEIRA, "Pelet", "Pelete", 0) /* linha 3870 */
R(R_INTEIRA, "Pinon", "Pinom", 0) /* linha 3871 */
R(R_INTEIRA, "Pison", "Pisom", 0) /* linha 3872 */
R(R_INTEIRA, "Piton", "Pitom", 0) /* linha 3873 */
R(R_INTEIRA, "Polux", "Pólux", 0) /* linha 3874 */
R(R_INTEIRA, "Rabit", "Rabite", 0) /* linha 3875 */
R(R_INTEIRA, "Racat", "Racate", 0) /* linha 3876 */
R(R_INTEIRA, "Racon", "Racom", 0) /* linha 3877 */
R(R_INTEIRA, "Raema", "Raama", 0) /* linha 3878 */
R(R_INTEIRA, "Ramah", "Rama", 0) /* linha 3879 */
R(R_INTEIRA, "Ramat", "Ramate", 0) /* linha 3880 */
R(R_INTEIRA, "Ramot", "Ramote", 0) /* linha 3881 */
R(R_INTEIRA, "Recab", "Recabe", 0) /* linha 3882 */
R(R_INTEIRA, "Recob", "Recobe", 0) /* linha 3883 */
R(R_INTEIRA, "Refah", "Refa", 0) /* linha 3884 */
R(R_INTEIRA, "Rehob", "Reobe", 0) /* linha 3885 */
R(R_INTEIRA, "Rehum", "Reum", 0) /* linha 3886 */
R(R_INTEIRA, "Rehun", "Reum", 0) /* linha 3887 */
R(R_INTEIRA, "Rekab", "Recabe", 0) /* linha 3888 */
R(R_INTEIRA, "Rekem", "Requem", 0) /* linha 3889 */
R(R_INTEIRA, "Remet", "Remete", 0) /* linha 3890 */
R(R_INTEIRA, "Resef", "Resefe", 0) /* linha 3891 */
R(R_INTEIRA, "Resin", "Resim", 0) /* linha 3892 */
R(R_INTEIRA, "Rezon", "Rezom", 0) /* linha 3893 */
R(R_INTEIRA, "Rhesa", "Resa", 0) /* linha 3894 */
R(R_INTEIRA, "Rhode", "Rode", 0) /* linha 3895 */
R(R_INTEIRA, "Rifat", "Rifate", 0) /* linha 3896 */
R(R_INTEIRA, "Rimon", "Rimom", 0) /* linha 3897 */
R(R_INTEIRA, "Safan", "Safã", 0) /* linha 3898 */
R(R_INTEIRA, "Safat", "Safate", 0) /* linha 3899 */
R(R_INTEIRA, "Safon", "Safom", 0) /* linha 3900 */
R(R_INTEIRA, "Salem", "Salém", 0) /* linha 3901 */
R(R_INTEIRA, "Samot", "Samote", 0) /* linha 3902 */
R(R_INTEIRA, "Saraf", "Sarafe", 0) /* linha 3903 */
R(R_INTEIRA, "Sarid", "Saride", 0) /* linha 3904 */
R(R_INTEIRA, "Saron", "Sarom", 0) /* linha 3905 */
R(R_INTEIRA, "Sasak", "Sasaque", 0) /* linha 3906 */
R(R_INTEIRA, "Sebat", "Sebate", 0) /* linha 3907 */
R(R_INTEIRA, "Segub", "Segube", 0) /* linha 3908 */
R(R_INTEIRA, "Sehon", "Seom", 0) /* linha 3909 */
R(R_INTEIRA, "Selah", "Selá", 0) /* linha 3910 */
R(R_INTEIRA, "Seled", "Selede", 0) /* linha 3911 */
R(R_INTEIRA, "Selef", "Selefe", 0) /* linha 3912 */
R(R_INTEIRA, "Sered", "Serede", 0) /* linha 3913 */
R(R_INTEIRA, "Serug", "Serugue", 0) /* linha 3914 */
R(R_INTEIRA, "Shuah", "Suah", 0) /* linha 3915 */
R(R_INTEIRA, "Shuni", "Suni", 0) /* linha 3916 */
R(R_INTEIRA, "Sidon", "Sidom", 0) /* linha 3917 */
R(R_INTEIRA, "Sihon", "Seom", 0) /* linha 3918 */
R(R_INTEIRA, "Sisak", "Sisaque", 0) /* linha 3919 */
R(R_INTEIRA, "Sobab", "Sobabe", 0) /* linha 3920 */
R(R_INTEIRA, "Sobek", "Sobeque", 0) /* linha 3921 */
R(R_INTEIRA, "Socho", "Soco", 0) /* linha 3922 */
R(R_INTEIRA, "Sochó", "Socó", 0) /* linha 3923 */
R(R_INTEIRA, "Socoh", "Soco", 0) /* linha 3924 */
R(R_INTEIRA, "Sofac", "Sofaque", 0) /* linha 3925 */
R(R_INTEIRA, "Sorec", "Soreque", 0) /* linha 3926 */
R(R_INTEIRA, "Sucot", "Sucote", 0) /* linha 3927 */
R(R_INTEIRA, "Tabat", "Tabate", 0) /* linha 3928 */
R(R_INTEIRA, "Tafat", "Tafate", 0) /* linha 3929 */
R(R_INTEIRA, "Tahat", "Tahate", 0) /* linha 3930 */
R(R_INTEIRA, "TEKEL", "TEQUEL", 0) /* linha 3931 */
R(R_INTEIRA, "Tekoa", "Tecoa", 0) /* linha 3932 */
R(R_INTEIRA, "Terah", "Terá", 0) /* linha 3933 */
R(R_INTEIRA, "Tikva", "Ticva", 0) /* linha 3934 */
R(R_INTEIRA, "Tilon", "Tilom", 0) /* linha 3935 */
R(R_INTEIRA, "Tofet", "Tofete", 0) /* linha 3936 */
R(R_INTEIRA, "Tolad", "Tolade", 0) /* linha 3937 */
R(R_INTEIRA, "Tsora", "Zora", 0) /* linha 3938 */
R(R_INTEIRA, "Vaheb", "Vahebe", 0) /* linha 3939 */
R(R_INTEIRA, "Zabad", "Zabade", 0) /* linha 3940 */
R(R_INTEIRA, "Zabud", "Zabude", 0) /* linha 3941 */
R(R_INTEIRA, "Zadoc", "Zadoque", 0) /* linha 3942 */
R(R_INTEIRA, "Zadok", "Zadoque", 0) /* linha 3943 */
R(R_INTEIRA, "Zalaf", "Zalafe", 0) /* linha 3944 */
R(R_INTEIRA, "Zedad", "Zedade", 0) /* linha 3945 */
R(R_INTEIRA, "Zefat", "Zefate", 0) /* linha 3946 */
R(R_INTEIRA, "Zefon", "Zefom", 0) /* linha 3947 */
R(R_INTEIRA, "Zelek", "Zeleque", 0) /* linha 3948 */
R(R_INTEIRA, "Zered", "Zerede", 0) /* linha 3949 */
R(R_INTEIRA, "Zeret", "Zerete", 0) /* linha 3950 */
R(R_INTEIRA, "Zidon", "Sidom", 0) /* linha 3951 */
R(R_INTEIRA, "Zohet", "Zohete", 0) /* linha 3952 */
R(R_INTEIRA, "Abib", "Abibe", 0) /* linha 3953 */
R(R_INTEIRA, "Acab", "Acabe", 0) /* linha 3954 */
R(R_INTEIRA, "Acad", "Acade", 0) /* linha 3955 */
R(R_INTEIRA, "Adah", "Ada", 0) /* linha 3956 */
R(R_INTEIRA, "Adon", "Adom", 0) /* linha 3957 */
R(R_INTEIRA, "Afek", "Afeque", 0) /* linha 3958 */
R(R_INTEIRA, "Afik", "Afique", 0) /* linha 3959 */
R(R_INTEIRA, "Agag", "Agague", 0) /* linha 3960 */
R(R_INTEIRA, "Ahab", "Acabe", 0) /* linha 3961 */
R(R_INTEIRA, "Aiat", "Aiate", 0) /* linha 3962 */
R(R_INTEIRA, "Ajah", "Aja", 0) /* linha 3963 */
R(R_INTEIRA, "Alef", "Álefe", 0) /* linha 3964 */
R(R_INTEIRA, "Alon", "Alom", 0) /* linha 3965 */
R(R_INTEIRA, "Alot", "Alote", 0) /* linha 3966 */
R(R_INTEIRA, "Amad", "Amade", 0) /* linha 3967 */
R(R_INTEIRA, "Amok", "Amoque", 0) /* linha 3968 */
R(R_INTEIRA, "Anab", "Anabe", 0) /* linha 3969 */
R(R_INTEIRA, "Anat", "Anate", 0) /* linha 3970 */
R(R_INTEIRA, "Anok", "Anoque", 0) /* linha 3971 */
R(R_INTEIRA, "Anub", "Anube", 0) /* linha 3972 */
R(R_INTEIRA, "Apio", "Ápio", 0) /* linha 3973 */
R(R_INTEIRA, "Arad", "Arade", 0) /* linha 3974 */
R(R_INTEIRA, "Arod", "Arode", 0) /* linha 3975 */
R(R_INTEIRA, "Asaf", "Asafe", 0) /* linha 3976 */
R(R_INTEIRA, "Avit", "Avite", 0) /* linha 3977 */
R(R_INTEIRA, "Azza", "Aza", 0) /* linha 3978 */
R(R_INTEIRA, "Chen", "Quen", 0) /* linha 3979 */
R(R_INTEIRA, "Chun", "Cun", 0) /* linha 3980 */
R(R_INTEIRA, "Doeg", "Doegue", 0) /* linha 3981 */
R(R_INTEIRA, "Ebad", "Ebade", 0) /* linha 3982 */
R(R_INTEIRA, "Ebed", "Ebede", 0) /* linha 3983 */
R(R_INTEIRA, "Echi", "Equi", 0) /* linha 3984 */
R(R_INTEIRA, "Efod", "Éfode", 0) /* linha 3985 */
R(R_INTEIRA, "Ehud", "Eúde", 0) /* linha 3986 */
R(R_INTEIRA, "Eker", "Equer", 0) /* linha 3987 */
R(R_INTEIRA, "Elat", "Elate", 0) /* linha 3988 */
R(R_INTEIRA, "Elef", "Elefe", 0) /* linha 3989 */
R(R_INTEIRA, "Elod", "Elode", 0) /* linha 3990 */
R(R_INTEIRA, "Elot", "Elote", 0) /* linha 3991 */
R(R_INTEIRA, "Enac", "Enaque", 0) /* linha 3992 */
R(R_INTEIRA, "Enak", "Enaque", 0) /* linha 3993 */
R(R_INTEIRA, "Esek", "Eseque", 0) /* linha 3994 */
R(R_INTEIRA, "Ezzi", "Ezi", 0) /* linha 3995 */
R(R_INTEIRA, "Gaas", "Gaás", 0) /* linha 3996 */
R(R_INTEIRA, "Giah", "Gia", 0) /* linha 3997 */
R(R_INTEIRA, "Goah", "Goa", 0) /* linha 3998 */
R(R_INTEIRA, "Irad", "Irade", 0) /* linha 3999 */
R(R_INTEIRA, "Jake", "Jaque", 0) /* linha 4000 */
R(R_INTEIRA, "Jehu", "Jeú", 0) /* linha 4001 */
R(R_INTEIRA, "Jeus", "Jeús", 0) /* linha 4002 */
R(R_INTEIRA, "Joab", "Joabe", 0) /* linha 4003 */
R(R_INTEIRA, "Joah", "Joá", 0) /* linha 4004 */
R(R_INTEIRA, "Joed", "Joede", 0) /* linha 4005 */
R(R_INTEIRA, "Juda", "Judá", 0) /* linha 4006 */
R(R_INTEIRA, "Kina", "Quina", 0) /* linha 4007 */
R(R_INTEIRA, "Kisi", "Quisi", 0) /* linha 4008 */
R(R_INTEIRA, "Koat", "Coate", 0) /* linha 4009 */
R(R_INTEIRA, "Kore", "Core", 0) /* linha 4010 */
R(R_INTEIRA, "Leah", "Lia", 0) /* linha 4011 */
R(R_INTEIRA, "Meah", "Meá", 0) /* linha 4012 */
R(R_INTEIRA, "Moab", "Moabe", 0) /* linha 4013 */
R(R_INTEIRA, "Nain", "Naim", 0) /* linha 4014 */
R(R_INTEIRA, "Obot", "Obote", 0) /* linha 4015 */
R(R_INTEIRA, "Oded", "Odede", 0) /* linha 4016 */
R(R_INTEIRA, "Ohad", "Oade", 0) /* linha 4017 */
R(R_INTEIRA, "Onan", "Onã", 0) /* linha 4018 */
R(R_INTEIRA, "Oreb", "Orebe", 0) /* linha 4019 */
R(R_INTEIRA, "Peka", "Peca", 0) /* linha 4020 */
R(R_INTEIRA, "Puah", "Pua", 0) /* linha 4021 */
R(R_INTEIRA, "Rehu", "Reú", 0) /* linha 4022 */
R(R_INTEIRA, "Saaf", "Saafe", 0) /* linha 4023 */
R(R_INTEIRA, "Saba", "Sabá", 0) /* linha 4024 */
R(R_INTEIRA, "Sion", "Siom", 0) /* linha 4025 */
R(R_INTEIRA, "Uzza", "Uza", 0) /* linha 4026 */
R(R_INTEIRA, "Uzzi", "Uzi", 0) /* linha 4027 */
R(R_INTEIRA, "Zeeb", "Zeebe", 0) /* linha 4028 */
R(R_INTEIRA, "Bet", "Bete", 0) /* linha 4029 */
R(R_INTEIRA, "Cub", "Cube", 0) /* linha 4030 */
R(R_INTEIRA, "Gad", "Gade", 0) /* linha 4031 */
R(R_INTEIRA, "Gob", "Gobe", 0) /* linha 4032 */
R(R_INTEIRA, "Hod", "Hode", 0) /* linha 4033 */
R(R_INTEIRA, "Iob", "Iobe", 0) /* linha 4034 */
R(R_INTEIRA, "Job", "Jó", 0) /* linha 4035 */
R(R_INTEIRA, "Kir", "Quir", 0) /* linha 4036 */
R(R_INTEIRA, "Kis", "Quis", 0) /* linha 4037 */
R(R_INTEIRA, "Kos", "Cós", 0) /* linha 4038 */
R(R_INTEIRA, "Kós", "Cós", 0) /* linha 4039 */
R(R_INTEIRA, "Lod", "Lode", 0) /* linha 4040 */
R(R_INTEIRA, "Lot", "Ló", 0) /* linha 4041 */
R(R_INTEIRA, "Lud", "Lude", 0) /* linha 4042 */
R(R_INTEIRA, "Mea", "Meá", 0) /* linha 4043 */
R(R_INTEIRA, "Nob", "Nobe", 0) /* linha 4044 */
R(R_INTEIRA, "Nod", "Node", 0) /* linha 4045 */
R(R_INTEIRA, "Nof", "Nofe", 0) /* linha 4046 */
R(R_INTEIRA, "Ólá", "Olá", 0) /* linha 4047 */
R(R_INTEIRA, "Poz", "Pôs", 0) /* linha 4048 */
R(R_INTEIRA, "Put", "Pute", 0) /* linha 4049 */
R(R_INTEIRA, "Saf", "Safe", 0) /* linha 4050 */
R(R_INTEIRA, "Suf", "Sufe", 0) /* linha 4051 */
R(R_INTEIRA, "Tob", "Tobe", 0) /* linha 4052 */
R(R_INTEIRA, "Zif", "Zife", 0) /* linha 4053 */
R(R_INTEIRA, "Zin", "Zim", 0) /* linha 4054 */
R(R_INTEIRA, "Ziv", "Zive", 0) /* linha 4055 */
R(R_INTEIRA, "Zuf", "Zufe", 0) /* linha 4056 */
R(R_INTEIRA, "Ed", "Ede", 0) /* linha 4057 */
R(R_INTEIRA, "Og", "Ogue", 0) /* linha 4058 */
R(R_INTEIRA, "On", "Om", 0) /* linha 4059 */
/* 12. REVISÃO DOS VERSÍCULOS (27/11/2026)
       Revisão de todos os 31.104 versículos (Claude Sonnet 5.5) com segunda opinião (Claude Opus 5.5).
       Tipo 1 = palavra inteira, quando TODAS as ocorrências na Bíblia foram aprovadas.
       Tipo 0 = trecho com as palavras vizinhas, que só existe nos versículos aprovados.
       Fonte: biblia-build/versos_rev/opus/decisoes*.tsv */
R(R_TEXTO, "Eis que veem dias", "Eis que vêm dias", 0) /* linha 4073 */
R(R_TEXTO, "eis que veem dias", "eis que vêm dias", 0) /* linha 4073 */
R(R_INTEIRA, "capiteis", "capitéis", 0) /* linha 4074 */
R(R_TEXTO, "e as suas utensílios em casa, não desça a tomá-las; e,", "e os seus utensílios em casa, não desça a tomá-los; e,", 0) /* linha 4075 */
R(R_TEXTO, "Porque eis que dias veem, diz o Senhor, em", "Porque eis que dias vêm, diz o Senhor, em", 0) /* linha 4076 */
R(R_TEXTO, "deleitando-se seus enganos, em ainda que", "deleitando-se em seus enganos, ainda que", 0) /* linha 4077 */
R(R_TEXTO, "disse-lhe: Porque não fizeste inquirição", "disse-lhe: Por que não fizeste inquirição", 0) /* linha 4078 */
R(R_TEXTO, "disse-lhes: Porque me tentais? trazei-me", "disse-lhes: Por que me tentais? trazei-me", 0) /* linha 4079 */
R(R_TEXTO, "e me lançaste para traz das tuas costas,", "e me lançaste para trás das tuas costas,", 0) /* linha 4080 */
R(R_TEXTO, "lhe disse: Porque me chamas bom? ninguém", "lhe disse: Por que me chamas bom? ninguém", 0) /* linha 4081 */
R(R_TEXTO, "os globos dos capiteis que estavam sobre", "os globos dos capitéis que estavam sobre", 0) /* linha 4082 */
R(R_TEXTO, "disse Jesus: Em verdade vos digo que um", "disse Jesus: Em verdade vós digo que um", 0) /* linha 4083 */
R(R_TEXTO, "disse: Dá-me uma benção; pois me deste", "disse: Dá-me uma bênção; pois me deste", 0) /* linha 4084 */
R(R_TEXTO, "me lançaste para traz das tuas costas;", "me lançaste para trás das tuas costas;", 0) /* linha 4085 */
R(R_TEXTO, "assolação, nem tão pouco haverá coisa", "assolação, nem tampouco haverá coisa", 0) /* linha 4086 */
R(R_TEXTO, "fortaleza; porque me rejeitas? porque", "fortaleza; por que me rejeitas? porque", 0) /* linha 4087 */
R(R_TEXTO, "isso eis que dias veem, diz o Senhor,", "isso eis que dias vêm, diz o Senhor,", 0) /* linha 4088 */
R(R_TEXTO, "oferecia oferta voluntaria ao Senhor:", "oferecia oferta voluntária ao Senhor:", 0) /* linha 4089 */
R(R_TEXTO, "subsistirá, nem tão pouco acontecerá.", "subsistirá, nem tampouco acontecerá.", 0) /* linha 4090 */
R(R_TEXTO, "alguma das vossas utensílios; porque", "alguma dos vossos utensílios; porque", 0) /* linha 4091 */
R(R_TEXTO, "coração: Porque me sobrevieram estas", "coração: Por que me sobrevieram estas", 0) /* linha 4092 */
R(R_TEXTO, "Deus, porque me desamparaste? porque", "Deus, por que me desamparaste? porque", 0) /* linha 4093 */
R(R_TEXTO, "oferta voluntaria de holocaustos, ou", "oferta voluntária de holocaustos, ou", 0) /* linha 4094 */
R(R_TEXTO, "temor, nem tão pouco vos assombreis.", "temor, nem tampouco vos assombreis.", 0) /* linha 4095 */
R(R_TEXTO, "estavam: Tiras os deuses estranhos,", "estavam: Tirai os deuses estranhos,", 0) /* linha 4096 */
R(R_TEXTO, "cala-te, porque te feririam? então", "cala-te, por que te feririam? então", 0) /* linha 4097 */
R(R_TEXTO, "desamparaste? porque te alongas do", "desamparaste? por que te alongas do", 0) /* linha 4098 */
R(R_TEXTO, "excederão as bençãos de meus pais,", "excederão as bênçãos de meus pais,", 0) /* linha 4099 */
R(R_TEXTO, "oferta voluntaria ao Senhor, então", "oferta voluntária ao Senhor, então", 0) /* linha 4100 */
R(R_TEXTO, "porque lançaste para traz das tuas", "porque lançaste para trás das tuas", 0) /* linha 4101 */
R(R_TEXTO, "Senhor, nem tão pouco vos rebeleis", "Senhor, nem tampouco vos rebeleis", 0) /* linha 4102 */
R(R_TEXTO, "deserto? porque nos fizeste isto,", "deserto? por que nos fizeste isto,", 0) /* linha 4103 */
R(R_TEXTO, "disse-lhes: Porque temeis, homens", "disse-lhes: Por que temeis, homens", 0) /* linha 4104 */
R(R_TEXTO, "dizer: Porque o perseguimos? Pois", "dizer: Por que o perseguimos? Pois", 0) /* linha 4105 */
R(R_TEXTO, "estes: Porque não acabastes vossa", "estes: Por que não acabastes vossa", 0) /* linha 4106 */
R(R_TEXTO, "nem tão pouco quem manifeste, nem", "nem tampouco quem manifeste, nem", 0) /* linha 4107 */
R(R_TEXTO, "peleja: nem tão pouco a impiedade", "peleja: nem tampouco a impiedade", 0) /* linha 4108 */
R(R_TEXTO, "terra, o aos sacerdotes, dizendo:", "terra, e aos sacerdotes, dizendo:", 0) /* linha 4109 */
R(R_TEXTO, "vestido, porque andais solícitos?", "vestido, por que andais solícitos?", 0) /* linha 4110 */
R(R_TEXTO, "Arnom, porque o não recuperastes", "Arnom, por que o não recuperastes", 0) /* linha 4111 */
R(R_TEXTO, "casa; porque te entremeterias no", "casa; por que te entremeterias no", 0) /* linha 4112 */
R(R_TEXTO, "Desperta, porque dormes, Senhor?", "Desperta, por que dormes, Senhor?", 0) /* linha 4113 */
R(R_TEXTO, "disse: Porque contendeis comigo?", "disse: Por que contendeis comigo?", 0) /* linha 4114 */
R(R_TEXTO, "Eis que dias veem, diz o Senhor,", "Eis que dias vêm, diz o Senhor,", 0) /* linha 4115 */
R(R_TEXTO, "eis que dias veem, diz o Senhor,", "eis que dias vêm, diz o Senhor,", 0) /* linha 4115 */
R(R_TEXTO, "fosse, porque se não angustiaria", "fosse, por que se não angustiaria", 0) /* linha 4116 */
R(R_TEXTO, "herança, come o Senhor ordenara,", "herança, como o Senhor ordenara,", 0) /* linha 4117 */
R(R_TEXTO, "mensageiros que veem a Jerusalém", "mensageiros que vêm a Jerusalém", 0) /* linha 4118 */
R(R_TEXTO, "palavra: assim ficou mulhendo, e", "palavra: assim ficou a mulher, e", 0) /* linha 4119 */
R(R_TEXTO, "profetas, tão pouco acreditarão,", "profetas, tampouco acreditarão,", 0) /* linha 4120 */
R(R_TEXTO, "rejeitas? porque ando lamentando", "rejeitas? por que ando lamentando", 0) /* linha 4121 */
R(R_TEXTO, "segundo, nem tão pouco filho nem", "segundo, nem tampouco filho nem", 0) /* linha 4122 */
R(R_TEXTO, "sempre? porque nos desampararias", "sempre? por que nos desampararias", 0) /* linha 4123 */
R(R_TEXTO, "todo o de mais sangue derramarás", "todo o demais sangue derramarás", 0) /* linha 4124 */
R(R_TEXTO, "dele; tão pouco os descendentes", "dele; tampouco os descendentes", 0) /* linha 4125 */
R(R_TEXTO, "disse: Porque nos fizeste subir", "disse: Por que nos fizeste subir", 0) /* linha 4126 */
R(R_TEXTO, "disseram-lhe: Porque lhes falas", "disseram-lhe: Por que lhes falas", 0) /* linha 4127 */
R(R_TEXTO, "espírito; nem tão pouco tem ele", "espírito; nem tampouco tem ele", 0) /* linha 4128 */
R(R_TEXTO, "nenhuma, nem tão pouco têm eles", "nenhuma, nem tampouco têm eles", 0) /* linha 4129 */
R(R_TEXTO, "a preza de abundantes despojos", "a presa de abundantes despojos", 0) /* linha 4130 */
R(R_TEXTO, "anunciar? porque razão pereceu", "anunciar? por que razão pereceu", 0) /* linha 4131 */
R(R_TEXTO, "chamar-te? porque não vieste a", "chamar-te? por que não vieste a", 0) /* linha 4132 */
R(R_TEXTO, "cobrir os capiteis que estavam", "cobrir os capitéis que estavam", 0) /* linha 4133 */
R(R_TEXTO, "consolação a que lhes causava.", "consolação que lhes causava.", 0) /* linha 4134 */
R(R_TEXTO, "Conta todo e primogênito macho", "Conta todo o primogênito macho", 0) /* linha 4135 */
R(R_TEXTO, "devoção voluntaria, humildade,", "devoção voluntária, humildade,", 0) /* linha 4136 */
R(R_TEXTO, "disse-lhes: Porque fazeis tais", "disse-lhes: Por que fazeis tais", 0) /* linha 4137 */
R(R_TEXTO, "disseram: Porque fizemos isso,", "disseram: Por que fizemos isso,", 0) /* linha 4138 */
R(R_TEXTO, "Israel, nem tão pouco dos reis", "Israel, nem tampouco dos reis", 0) /* linha 4139 */
R(R_TEXTO, "nem tão pouco dos entendidos o", "nem tampouco dos entendidos o", 0) /* linha 4140 */
R(R_TEXTO, "nem tão pouco dos prudentes as", "nem tampouco dos prudentes as", 0) /* linha 4141 */
R(R_TEXTO, "ou injuria por injuria; antes,", "ou injúria por injúria; antes,", 0) /* linha 4142 */
R(R_TEXTO, "pois, porque morreríamos? pois", "pois, por que morreríamos? pois", 0) /* linha 4143 */
R(R_TEXTO, "Rocha: Porque te esqueceste de", "Rocha: Por que te esqueceste de", 0) /* linha 4144 */
R(R_TEXTO, "saber porque contendes comigo.", "saber por que contendes comigo.", 0) /* linha 4145 */
R(R_TEXTO, "Samaria; e Benjamin a Gileade.", "Samaria; e Benjamim a Gileade.", 0) /* linha 4146 */
R(R_TEXTO, "segundo as sua gerações, foram", "segundo as suas gerações, foram", 0) /* linha 4147 */
R(R_TEXTO, "Senhor? Porque te escondes nos", "Senhor? Por que te escondes nos", 0) /* linha 4148 */
R(R_TEXTO, "Abraão, da tribo de Benjamin.", "Abraão, da tribo de Benjamim.", 0) /* linha 4149 */
R(R_TEXTO, "Acazias: Traição ha, Acazias.", "Acazias: Traição há, Acazias.", 0) /* linha 4150 */
R(R_TEXTO, "apostasia tão continua? retem", "apostasia tão contínua? retem", 0) /* linha 4151 */
R(R_TEXTO, "contínua? retem o engano, não", "contínua? retém o engano, não", 0) /* linha 4152 */
R(R_TEXTO, "dada subsistência continua, a", "dada subsistência contínua, a", 0) /* linha 4153 */
R(R_TEXTO, "deles: porque não lhas destes", "deles: por que não lhas destes", 0) /* linha 4154 */
R(R_TEXTO, "Deus? porque seremos desleais", "Deus? por que seremos desleais", 0) /* linha 4155 */
R(R_TEXTO, "disse: Porque buscaste deuses", "disse: Por que buscaste deuses", 0) /* linha 4156 */
R(R_TEXTO, "disse: Porque perguntas assim", "disse: Por que perguntas assim", 0) /* linha 4157 */
R(R_TEXTO, "disse-lhe: Porque achei graça", "disse-lhe: Por que achei graça", 0) /* linha 4158 */
R(R_TEXTO, "disserem: Porque suspiras tu?", "disserem: Por que suspiras tu?", 0) /* linha 4159 */
R(R_TEXTO, "Dizendo: Porque jejuamos nós,", "Dizendo: Por que jejuamos nós,", 0) /* linha 4160 */
R(R_TEXTO, "escribas: Porque não andam os", "escribas: Por que não andam os", 0) /* linha 4161 */
R(R_TEXTO, "filhas, porque iríeis comigo?", "filhas, por que iríeis comigo?", 0) /* linha 4162 */
R(R_TEXTO, "fino, e purpura, e escarlata;", "fino, e púrpura, e escarlata;", 0) /* linha 4163 */
R(R_TEXTO, "Josué, e disserem: Porque com", "Josué, e disseram: Porque com", 0) /* linha 4164 */
R(R_TEXTO, "perguntaram-lhe: Pois que? És", "perguntaram-lhe: Pois quê? És", 0) /* linha 4165 */
R(R_TEXTO, "Porque te glórias na malícia,", "Porque te glorias na malícia,", 0) /* linha 4166 */
R(R_TEXTO, "pronunciarás a benção sobre o", "pronunciarás a bênção sobre o", 0) /* linha 4167 */
R(R_TEXTO, "Senhor, nem tão pouco a obra,", "Senhor, nem tampouco a obra,", 0) /* linha 4168 */
R(R_TEXTO, "a perseverança e suplica por", "a perseverança e súplica por", 0) /* linha 4169 */
R(R_TEXTO, "agora, nem tão pouco haverá.", "agora, nem tampouco haverá.", 0) /* linha 4170 */
R(R_TEXTO, "angústia! porque serias como", "angústia! por que serias como", 0) /* linha 4171 */
R(R_TEXTO, "azul, e purpura, e carmesim,", "azul, e púrpura, e carmesim,", 0) /* linha 4172 */
R(R_TEXTO, "caminhos? Porque endureces o", "caminhos? Por que endureces o", 0) /* linha 4173 */
R(R_TEXTO, "disse: Porque caminho passou", "disse: Por que caminho passou", 0) /* linha 4174 */
R(R_TEXTO, "dizendo: Porque jejuamos nós", "dizendo: Por que jejuamos nós", 0) /* linha 4175 */
R(R_TEXTO, "E porque me chamais, Senhor,", "E por que me chamais, Senhor,", 0) /* linha 4176 */
R(R_TEXTO, "e porque te perturbas dentro", "e por que te perturbas dentro", 0) /* linha 4177 */
R(R_TEXTO, "escuridão? porque pois diz o", "escuridão? por que pois diz o", 0) /* linha 4178 */
R(R_TEXTO, "gentios, a nossa vista, pela", "gentios, à nossa vista, pela", 0) /* linha 4179 */
R(R_TEXTO, "Judá: Porque subistes contra", "Judá: Por que subistes contra", 0) /* linha 4180 */
R(R_TEXTO, "mal, nem tão pouco têm poder", "mal, nem tampouco têm poder", 0) /* linha 4181 */
R(R_TEXTO, "médico? porque pois não teve", "médico? por que pois não teve", 0) /* linha 4182 */
R(R_TEXTO, "oferta voluntaria, oferecida", "oferta voluntária, oferecida", 0) /* linha 4183 */
R(R_TEXTO, "para os capiteis que estavam", "para os capitéis que estavam", 0) /* linha 4184 */
R(R_TEXTO, "porém senão lha restituíres,", "porém se não lha restituíres,", 0) /* linha 4185 */
R(R_TEXTO, "Porém vos não vos detenhais;", "Porém vós não vos detenhais;", 0) /* linha 4186 */
R(R_TEXTO, "povo? porque te assentas só,", "povo? por que te assentas só,", 0) /* linha 4187 */
R(R_TEXTO, "superior de Benjamin, a qual", "superior de Benjamim, a qual", 0) /* linha 4188 */
R(R_TEXTO, "vem, e enviar-te-hei a eles.", "vem, e enviar-te-ei a eles.", 0) /* linha 4189 */
R(R_TEXTO, "Aarão, porque fazeis cessar", "Aarão, por que fazeis cessar", 0) /* linha 4190 */
R(R_TEXTO, "bosques de Arabia passareis", "bosques de Arábia passareis", 0) /* linha 4191 */
R(R_TEXTO, "carro? porque se demoram os", "carro? por que se demoram os", 0) /* linha 4192 */
R(R_TEXTO, "companheiro: Porque obrou o", "companheiro: Por que obrou o", 0) /* linha 4193 */
R(R_TEXTO, "contaminei em os seus dons,", "contaminei nos seus dons,", 0) /* linha 4194 */
R(R_TEXTO, "contemplam, o Deus, Senhor:", "contemplam, ó Deus, Senhor:", 0) /* linha 4195 */
R(R_TEXTO, "despiram-lhe a purpura, e o", "despiram-lhe a púrpura, e o", 0) /* linha 4196 */
R(R_TEXTO, "Deus: Porque transgredis os", "Deus: Por que transgredis os", 0) /* linha 4197 */
R(R_TEXTO, "disse: Porque quebrantais o", "disse: Por que quebrantais o", 0) /* linha 4198 */
R(R_TEXTO, "disse-lhe: O mulher! grande", "disse-lhe: Ó mulher! grande", 0) /* linha 4199 */
R(R_TEXTO, "disser: Porque fazeis isso?", "disser: Por que fazeis isso?", 0) /* linha 4200 */
R(R_TEXTO, "disseram-lhe: Ha ainda para", "disseram-lhe: Há ainda para", 0) /* linha 4201 */
R(R_TEXTO, "disseram-lhe: O nossa irmã,", "disseram-lhe: Ó nossa irmã,", 0) /* linha 4202 */
R(R_TEXTO, "disserdes: Porque nos fez o", "disserdes: Por que nos fez o", 0) /* linha 4203 */
R(R_TEXTO, "dizendo: Porque fazes assim", "dizendo: Por que fazes assim", 0) /* linha 4204 */
R(R_TEXTO, "entesourem para si mesmo um", "entesourem para si mesmos um", 0) /* linha 4205 */
R(R_TEXTO, "Filho, porque fizeste assim", "Filho, por que fizeste assim", 0) /* linha 4206 */
R(R_TEXTO, "filhos de Benjamin, do meio", "filhos de Benjamim, do meio", 0) /* linha 4207 */
R(R_TEXTO, "folha da corôa de santidade", "folha da coroa de santidade", 0) /* linha 4208 */
R(R_TEXTO, "forno: em escorias de prata", "forno: em escórias de prata", 0) /* linha 4209 */
R(R_TEXTO, "Israel, porque sucedeu isto", "Israel, por que sucedeu isto", 0) /* linha 4210 */
R(R_TEXTO, "levando a corôa de espinhos", "levando a coroa de espinhos", 0) /* linha 4211 */
R(R_TEXTO, "médico, nem tão pouco há em", "médico, nem tampouco há em", 0) /* linha 4212 */
R(R_TEXTO, "mim? porque ando lamentando", "mim? por que ando lamentando", 0) /* linha 4213 */
R(R_TEXTO, "Moisés: Porque nos fizestes", "Moisés: Por que nos fizestes", 0) /* linha 4214 */
R(R_TEXTO, "parte: Porque o não podemos", "parte: Por que o não podemos", 0) /* linha 4215 */
R(R_TEXTO, "pela meia noite suspeitaram", "pela meia-noite suspeitaram", 0) /* linha 4216 */
R(R_TEXTO, "penas de varias cores, veio", "penas de várias cores, veio", 0) /* linha 4217 */
R(R_TEXTO, "Porque nos assentamos aqui?", "Por que nos assentamos aqui?", 0) /* linha 4218 */
R(R_TEXTO, "receberá a benção do Senhor", "receberá a bênção do Senhor", 0) /* linha 4219 */
R(R_TEXTO, "seu pagem de armas: Arranca", "seu pajem de armas: Arranca", 0) /* linha 4220 */
R(R_TEXTO, "Sião? porque nos feriste de", "Sião? por que nos feriste de", 0) /* linha 4221 */
R(R_TEXTO, "tiraria a preza ao valente?", "tiraria a presa ao valente?", 0) /* linha 4222 */
R(R_TEXTO, "virados para traz, cobriram", "virados para trás, cobriram", 0) /* linha 4223 */
R(R_TEXTO, "agora, nem tão pouco há de", "agora, nem tampouco há de", 0) /* linha 4224 */
R(R_TEXTO, "apanhar a preza: e devorou", "apanhar a presa: e devorou", 0) /* linha 4225 */
R(R_TEXTO, "coração voluntariamente se", "coração voluntáriamente se", 0) /* linha 4226 */
R(R_TEXTO, "de varias concupiscências;", "de várias concupiscências;", 0) /* linha 4227 */
R(R_TEXTO, "de, encurvando me, desatar", "de, encurvando-me, desatar", 0) /* linha 4228 */
R(R_TEXTO, "depois pacifica, moderada,", "depois pacífica, moderada,", 0) /* linha 4229 */
R(R_TEXTO, "disse: Porque ajuizais mal", "disse: Por que ajuizais mal", 0) /* linha 4230 */
R(R_TEXTO, "disse: Porque não reparais", "disse: Por que não reparais", 0) /* linha 4231 */
R(R_TEXTO, "dizendo: Donde veem a este", "dizendo: Donde vêm a este", 0) /* linha 4232 */
R(R_TEXTO, "estes que veem voando como", "estes que vêm voando como", 0) /* linha 4233 */
R(R_TEXTO, "estranhos por preza, e aos", "estranhos por presa, e aos", 0) /* linha 4234 */
R(R_TEXTO, "Israel: Porque nos feriu o", "Israel: Por que nos feriu o", 0) /* linha 4235 */
R(R_TEXTO, "manjares de ciumes, oferta", "manjares de ciúmes, oferta", 0) /* linha 4236 */
R(R_TEXTO, "mãos: porque pois subistes", "mãos: por que pois subistes", 0) /* linha 4237 */
R(R_TEXTO, "nações, que ás de possuir,", "nações, que hás de possuir,", 0) /* linha 4238 */
R(R_TEXTO, "nem tão pouco dos sábios o", "nem tampouco dos sábios o", 0) /* linha 4239 */
R(R_TEXTO, "nem tão pouco quem ouça as", "nem tampouco quem ouça as", 0) /* linha 4240 */
R(R_TEXTO, "Portanto, tornar-me-hei, e", "Portanto, tornar-me-ei, e", 0) /* linha 4241 */
R(R_TEXTO, "protestarei contia ti; Sou", "protestarei contra ti; Sou", 0) /* linha 4242 */
R(R_TEXTO, "quando vos entregaram, não", "quando vos entregarem, não", 0) /* linha 4243 */
R(R_TEXTO, "quanto neles ha, jubilarão", "quanto neles há, jubilarão", 0) /* linha 4244 */
R(R_TEXTO, "rei, nem tão pouco no mais", "rei, nem tampouco no mais", 0) /* linha 4245 */
R(R_TEXTO, "segundo a benção do Senhor", "segundo a bênção do Senhor", 0) /* linha 4246 */
R(R_TEXTO, "Senhor! porque fizeste mal", "Senhor! por que fizeste mal", 0) /* linha 4247 */
R(R_TEXTO, "seu pagem de armas estavam", "seu pajem de armas estavam", 0) /* linha 4248 */
R(R_TEXTO, "seu pagem de armas feriram", "seu pajem de armas feriram", 0) /* linha 4249 */
R(R_TEXTO, "tornastes em escorias, por", "tornastes em escórias, por", 0) /* linha 4250 */
R(R_TEXTO, "tornaste-te para traz; por", "tornaste-te para trás; por", 0) /* linha 4251 */
R(R_TEXTO, "Tu, que te glórias na lei,", "Tu, que te glorias na lei,", 0) /* linha 4252 */
R(R_TEXTO, "voltaram para traz, caíram", "voltaram para trás, caíram", 0) /* linha 4253 */
R(R_TEXTO, "voz. Porque fizestes isto?", "voz. Por que fizestes isto?", 0) /* linha 4254 */
R(R_TEXTO, "cabeças, a corôa de vossa", "cabeças, a coroa de vossa", 0) /* linha 4255 */
R(R_TEXTO, "com bençãos do abismo que", "com bênçãos do abismo que", 0) /* linha 4256 */
R(R_TEXTO, "comigo? porque tentais ao", "comigo? por que tentais ao", 0) /* linha 4257 */
R(R_TEXTO, "conosco, porque tudo isto", "conosco, por que tudo isto", 0) /* linha 4258 */
R(R_TEXTO, "da meia noite, havendo-se", "da meia-noite, havendo-se", 0) /* linha 4259 */
R(R_TEXTO, "dar em nós mesmo exemplo,", "dar em nós mesmos exemplo,", 0) /* linha 4260 */
R(R_TEXTO, "das suas dizimas resgatar", "das suas dízimas resgatar", 0) /* linha 4261 */
R(R_TEXTO, "de todos os moveis da tua", "de todos os móveis da tua", 0) /* linha 4262 */
R(R_TEXTO, "de varias cores, despojos", "de várias cores, despojos", 0) /* linha 4263 */
R(R_TEXTO, "descerá ante dos olhos de", "descerá diante dos olhos de", 0) /* linha 4264 */
R(R_TEXTO, "discípulos: Porque come o", "discípulos: Por que come o", 0) /* linha 4265 */
R(R_TEXTO, "disseram: Porque fazeis o", "disseram: Por que fazeis o", 0) /* linha 4266 */
R(R_TEXTO, "dizeis: Porque não levará", "dizeis: Por que não levará", 0) /* linha 4267 */
R(R_TEXTO, "dizendo: Porque viriam os", "dizendo: Por que viriam os", 0) /* linha 4268 */
R(R_TEXTO, "durará a corôa de geração", "durará a coroa de geração", 0) /* linha 4269 */
R(R_TEXTO, "e azul celeste, pendentes", "e azul-celeste, pendentes", 0) /* linha 4270 */
R(R_TEXTO, "e Eleal, as e Quiriataim;", "e Eleale, e Quiriataim;", 0) /* linha 4271 */
R(R_TEXTO, "E os capiteis que estavam", "E os capitéis que estavam", 0) /* linha 4272 */
R(R_TEXTO, "e perpetua alegria haverá", "e perpétua alegria haverá", 0) /* linha 4273 */
R(R_TEXTO, "e porque te entremeterias", "e por que te entremeterias", 0) /* linha 4274 */
R(R_TEXTO, "fino e purpura, e argolas", "fino e púrpura, e argolas", 0) /* linha 4275 */
R(R_TEXTO, "fortes; e veem, e devoram", "fortes; e vêm, e devoram", 0) /* linha 4276 */
R(R_TEXTO, "gordura que neles ha, que", "gordura que neles há, que", 0) /* linha 4277 */
R(R_TEXTO, "homens? porque fizeste de", "homens? por que fizeste de", 0) /* linha 4278 */
R(R_TEXTO, "instrumentos de musica; e", "instrumentos de música; e", 0) /* linha 4279 */
R(R_TEXTO, "irmão, ás de servir-me de", "irmão, hás de servir-me de", 0) /* linha 4280 */
R(R_TEXTO, "isso? Porque afligimos as", "isso? Por que afligimos as", 0) /* linha 4281 */
R(R_TEXTO, "juízos. Porque prospera o", "juízos. Por que prospera o", 0) /* linha 4282 */
R(R_TEXTO, "manjares dos ciumes, porá", "manjares dos ciúmes, porá", 0) /* linha 4283 */
R(R_TEXTO, "manjares, duas dizimas de", "manjares, duas dízimas de", 0) /* linha 4284 */
R(R_TEXTO, "Misma, e De uma, e Masca,", "Misma, e Dumá, e Masca,", 0) /* linha 4285 */
R(R_TEXTO, "Misma, e De uma, e Massa,", "Misma, e Duma, e Massa,", 0) /* linha 4286 */
R(R_TEXTO, "Nem tão pouco apresenteis", "Nem tampouco apresenteis", 0) /* linha 4287 */
R(R_TEXTO, "nem tão pouco derramareis", "nem tampouco derramareis", 0) /* linha 4288 */
R(R_TEXTO, "nem tão pouco pretendemos", "nem tampouco pretendemos", 0) /* linha 4289 */
R(R_TEXTO, "nisto; porque cresceria o", "nisto; por que cresceria o", 0) /* linha 4290 */
R(R_TEXTO, "o espírito de ciumes vier", "o espírito de ciúmes vier", 0) /* linha 4291 */
R(R_TEXTO, "olhando para traz, disse:", "olhando para trás, disse:", 0) /* linha 4292 */
R(R_TEXTO, "pela vida o homicida, que", "pela vida do homicida, que", 0) /* linha 4293 */
R(R_TEXTO, "Porque contendeis comigo?", "Por que contendeis comigo?", 0) /* linha 4294 */
R(R_TEXTO, "Porque me perseguis assim", "Por que me perseguis assim", 0) /* linha 4295 */
R(R_TEXTO, "povo; se a ás de redimir,", "povo; se a hás de redimir,", 0) /* linha 4296 */
R(R_TEXTO, "povo? porque me enviaste?", "povo? por que me enviaste?", 0) /* linha 4297 */
R(R_TEXTO, "quem ás de enviar comigo:", "quem hás de enviar comigo:", 0) /* linha 4298 */
R(R_TEXTO, "retiraram-se para traz, e", "retiraram-se para trás, e", 0) /* linha 4299 */
R(R_TEXTO, "semente? Porque tem então", "semente? Por que tem então", 0) /* linha 4300 */
R(R_TEXTO, "será chamada adultera, se", "será chamada adúltera, se", 0) /* linha 4301 */
R(R_TEXTO, "a varias concupiscências", "a várias concupiscências", 0) /* linha 4302 */
R(R_TEXTO, "aonde ás de entrar; para", "aonde hás de entrar; para", 0) /* linha 4303 */
R(R_TEXTO, "apressou era prepará-la.", "apressou em prepará-la.", 0) /* linha 4304 */
R(R_TEXTO, "casa? porque pois veio a", "casa? por que pois veio a", 0) /* linha 4305 */
R(R_TEXTO, "certamente ás de reinar,", "certamente hás de reinar,", 0) /* linha 4306 */
R(R_TEXTO, "com bençãos dos peitos e", "com bênçãos dos peitos e", 0) /* linha 4307 */
R(R_TEXTO, "comiam os primeiras sete", "comiam as primeiras sete", 0) /* linha 4308 */
R(R_TEXTO, "disseram aos Cabeças dos", "disseram aos cabeças dos", 0) /* linha 4309 */
R(R_TEXTO, "dizendo: Porque comeis e", "dizendo: Por que comeis e", 0) /* linha 4310 */
R(R_TEXTO, "dizendo: Porque dizem os", "dizendo: Por que dizem os", 0) /* linha 4311 */
R(R_TEXTO, "e ha-te já valorosamente", "e há-te já valorosamente", 0) /* linha 4312 */
R(R_TEXTO, "e porque te perturbas em", "e por que te perturbas em", 0) /* linha 4313 */
R(R_TEXTO, "e solver duvidas: agora,", "e solver dúvidas: agora,", 0) /* linha 4314 */
R(R_TEXTO, "entre a purpura, e entre", "entre a púrpura, e entre", 0) /* linha 4315 */
R(R_TEXTO, "esquivar-se de ali entre", "esquivar-se dali entre", 0) /* linha 4316 */
R(R_TEXTO, "filhas dous homens desta", "filhas dos homens desta", 0) /* linha 4317 */
R(R_TEXTO, "gente sabia e entendida.", "gente sábia e entendida.", 0) /* linha 4318 */
R(R_TEXTO, "globos dos capiteis, que", "globos dos capitéis, que", 0) /* linha 4319 */
R(R_TEXTO, "Israel: A tarde sabereis", "Israel: À tarde sabereis", 0) /* linha 4320 */
R(R_TEXTO, "Jefté: Porque passaste a", "Jefté: Por que passaste a", 0) /* linha 4321 */
R(R_TEXTO, "Jordão voltou para traz.", "Jordão voltou para trás.", 0) /* linha 4322 */
R(R_TEXTO, "maravilhas de aquele que", "maravilhas daquele que", 0) /* linha 4323 */
R(R_TEXTO, "mulher tiver ciumes, por", "mulher tiver ciúmes, por", 0) /* linha 4324 */
R(R_TEXTO, "multidão doa anos ensine", "multidão dos anos ensine", 0) /* linha 4325 */
R(R_TEXTO, "nenhum vos fiéis; porque", "nenhum vos fieis; porque", 0) /* linha 4326 */
R(R_TEXTO, "o meio dia, profetizaram", "o meio-dia, profetizaram", 0) /* linha 4327 */
R(R_TEXTO, "oferta voluntaria, assim", "oferta voluntária, assim", 0) /* linha 4328 */
R(R_TEXTO, "Porque te desvias tanto,", "Por que te desvias tanto,", 0) /* linha 4329 */
R(R_TEXTO, "que estilo na Judeia, em", "que estão na Judeia, em", 0) /* linha 4330 */
R(R_TEXTO, "que retem violentamente,", "que retém violentamente,", 0) /* linha 4331 */
R(R_TEXTO, "recebe a benção de Deus:", "recebe a bênção de Deus:", 0) /* linha 4332 */
R(R_TEXTO, "Samuel: Vai te deitar, e", "Samuel: Vai-te deitar, e", 0) /* linha 4333 */
R(R_TEXTO, "seu pagem de armas atrás", "seu pajem de armas atrás", 0) /* linha 4334 */
R(R_TEXTO, "terra de Benjamin, e das", "terra de Benjamim, e das", 0) /* linha 4335 */
R(R_TEXTO, "tornaram-se para traz, e", "tornaram-se para trás, e", 0) /* linha 4336 */
R(R_TEXTO, "a minha benção sobre os", "a minha bênção sobre os", 0) /* linha 4337 */
R(R_TEXTO, "ajuntam veem a ti: vivo", "ajuntam vêm a ti: vivo", 0) /* linha 4338 */
R(R_TEXTO, "ajuntaram, e veem a ti:", "ajuntaram, e vêm a ti:", 0) /* linha 4339 */
R(R_TEXTO, "alma voluntaria; porque", "alma voluntária; porque", 0) /* linha 4340 */
R(R_TEXTO, "Antes, porque-vos tenho", "Antes, porque vos tenho", 0) /* linha 4341 */
R(R_TEXTO, "Arab, e De uma, e Esan,", "Arab, e Duma, e Esan,", 0) /* linha 4342 */
R(R_TEXTO, "arrebatam a preza, para", "arrebatam a presa, para", 0) /* linha 4343 */
R(R_TEXTO, "bases de baixo de outra", "bases debaixo de outra", 0) /* linha 4344 */
R(R_TEXTO, "com bençãos dos céus de", "com bênçãos dos céus de", 0) /* linha 4345 */
R(R_TEXTO, "com perpetua inimizade,", "com perpétua inimizade,", 0) /* linha 4346 */
R(R_TEXTO, "coxos roubarão a preza.", "coxos roubarão a presa.", 0) /* linha 4347 */
R(R_TEXTO, "da corôa de soberba dos", "da coroa de soberba dos", 0) /* linha 4348 */
R(R_TEXTO, "Dan porque se deteve em", "Dan por que se deteve em", 0) /* linha 4349 */
R(R_TEXTO, "de manjares continua; a", "de manjares contínua; a", 0) /* linha 4350 */
R(R_TEXTO, "dentro dos tuas portas;", "dentro das tuas portas;", 0) /* linha 4351 */
R(R_TEXTO, "disse: Porque pede esta", "disse: Por que pede esta", 0) /* linha 4352 */
R(R_TEXTO, "disser: Ha aqui alguém?", "disser: Há aqui alguém?", 0) /* linha 4353 */
R(R_TEXTO, "disseram: Ha alguma das", "disseram: Há alguma das", 0) /* linha 4354 */
R(R_TEXTO, "disserem: Porque fala o", "disserem: Por que fala o", 0) /* linha 4355 */
R(R_TEXTO, "do Todo Poderoso, caído", "do Todo-Poderoso, caído", 0) /* linha 4356 */
R(R_TEXTO, "e a continua oferta dos", "e a contínua oferta dos", 0) /* linha 4357 */
R(R_TEXTO, "e apiedar-me-hei deles.", "e apiedar-me-ei deles.", 0) /* linha 4358 */
R(R_TEXTO, "E porque me não perdoas", "E por que me não perdoas", 0) /* linha 4359 */
R(R_TEXTO, "errei grandissimamente.", "errei grandíssimamente.", 0) /* linha 4360 */
R(R_TEXTO, "espírito se angústia em", "espírito se angustia em", 0) /* linha 4361 */
R(R_TEXTO, "espirituais em os ares.", "espirituais nos ares.", 0) /* linha 4362 */
R(R_TEXTO, "estranha distilam favos", "estranha destilam favos", 0) /* linha 4363 */
R(R_TEXTO, "excelência perpetua, um", "excelência perpétua, um", 0) /* linha 4364 */
R(R_TEXTO, "Hai para traz, olharam,", "Hai para trás, olharam,", 0) /* linha 4365 */
R(R_TEXTO, "homem, te constitui por", "homem, te constituí por", 0) /* linha 4366 */
R(R_TEXTO, "Judá, que veem a adorar", "Judá, que vêm a adorar", 0) /* linha 4367 */
R(R_TEXTO, "Moisés: Porque clamas a", "Moisés: Por que clamas a", 0) /* linha 4368 */
R(R_TEXTO, "nem tão pouco desejarão", "nem tampouco desejarão", 0) /* linha 4369 */
R(R_TEXTO, "nem tão pouco esperarão", "nem tampouco esperarão", 0) /* linha 4370 */
R(R_TEXTO, "o espírito de ciumes, e", "o espírito de ciúmes, e", 0) /* linha 4371 */
R(R_TEXTO, "passar deste mando para", "passar deste mundo para", 0) /* linha 4372 */
R(R_TEXTO, "Peso contra Arabia. Nos", "Peso contra Arábia. Nos", 0) /* linha 4373 */
R(R_TEXTO, "porém tão pouco estavam", "porém tampouco estavam", 0) /* linha 4374 */
R(R_TEXTO, "Porém tão pouco ouviram", "Porém tampouco ouviram", 0) /* linha 4375 */
R(R_TEXTO, "porque adulteras são, e", "porque adúlteras são, e", 0) /* linha 4376 */
R(R_TEXTO, "Porque estás abatida, ó", "Por que estás abatida, ó", 0) /* linha 4377 */
R(R_TEXTO, "porque hei-de enviar-te", "porque hei de enviar-te", 0) /* linha 4378 */
R(R_TEXTO, "Porque pois descorajais", "Por que pois descorajais", 0) /* linha 4379 */
R(R_TEXTO, "porque te glórias, como", "porque te glorias, como", 0) /* linha 4380 */
R(R_TEXTO, "profetas virão para ti,", "profetas viram para ti,", 0) /* linha 4381 */
R(R_TEXTO, "quando hei-de trabalhar", "quando hei de trabalhar", 0) /* linha 4382 */
R(R_TEXTO, "que retem violentamente", "que retém violentamente", 0) /* linha 4383 */
R(R_TEXTO, "roubar as utensílios do", "roubar os utensílios do", 0) /* linha 4384 */
R(R_TEXTO, "Senhor: porque pois não", "Senhor: por que pois não", 0) /* linha 4385 */
R(R_TEXTO, "também fábrica dele uma", "também fabrica dele uma", 0) /* linha 4386 */
R(R_TEXTO, "tempos porque, os que o", "tempos por que, os que o", 0) /* linha 4387 */
R(R_TEXTO, "terão perpetua alegria.", "terão perpétua alegria.", 0) /* linha 4388 */
R(R_TEXTO, "toda a benção e louvor.", "toda a bênção e louvor.", 0) /* linha 4389 */
R(R_TEXTO, "todos os moveis da casa", "todos os móveis da casa", 0) /* linha 4390 */
R(R_TEXTO, "tornará para traz sobre", "tornará para trás sobre", 0) /* linha 4391 */
R(R_TEXTO, "uma mulher sabia gritou", "uma mulher sábia gritou", 0) /* linha 4392 */
R(R_TEXTO, "vistes: porque pois vos", "vistes: por que pois vos", 0) /* linha 4393 */
R(R_TEXTO, "voltem para traz, todos", "voltem para trás, todos", 0) /* linha 4394 */
R(R_TEXTO, "zombaria de aqueles que", "zombaria daqueles que", 0) /* linha 4395 */
R(R_TEXTO, "A corôa de soberba dos", "A coroa de soberba dos", 0) /* linha 4396 */
R(R_TEXTO, "adversário não ha, nem", "adversário não há, nem", 0) /* linha 4397 */
R(R_TEXTO, "alguma: tão pouco virá", "alguma: tampouco virá", 0) /* linha 4398 */
R(R_TEXTO, "apressurou-se à preza.", "apressurou-se à presa.", 0) /* linha 4399 */
R(R_TEXTO, "arrebata a preza: eles", "arrebata a presa: eles", 0) /* linha 4400 */
R(R_TEXTO, "arrebatarão a preza, e", "arrebatarão a presa, e", 0) /* linha 4401 */
R(R_TEXTO, "as bençãos espirituais", "as bênçãos espirituais", 0) /* linha 4402 */
R(R_TEXTO, "benignidade sustem ele", "benignidade sustém ele", 0) /* linha 4403 */
R(R_TEXTO, "confundir as sabias; e", "confundir as sábias; e", 0) /* linha 4404 */
R(R_TEXTO, "contigo de aqui trinta", "contigo daqui trinta", 0) /* linha 4405 */
R(R_TEXTO, "de moveis apetecíveis.", "de móveis apetecíveis.", 0) /* linha 4406 */
R(R_TEXTO, "de varias enfermidades", "de várias enfermidades", 0) /* linha 4407 */
R(R_TEXTO, "deles: porque pois vos", "deles: por que pois vos", 0) /* linha 4408 */
R(R_TEXTO, "disse: Eis-aqui, tenho", "disse: Eis aqui, tenho", 0) /* linha 4409 */
R(R_TEXTO, "disse: Ha acaso alguma", "disse: Há acaso alguma", 0) /* linha 4410 */
R(R_TEXTO, "disse: Porque é que me", "disse: Por que é que me", 0) /* linha 4411 */
R(R_TEXTO, "dizeis: Porque? porque", "dizeis: Por quê? porque", 0) /* linha 4412 */
R(R_TEXTO, "dizendo: Eis-aqui, nós", "dizendo: Eis aqui, nós", 0) /* linha 4413 */
R(R_TEXTO, "do candieiro alumiarão", "do candeeiro alumiarão", 0) /* linha 4414 */
R(R_TEXTO, "e congregar-vos-hei de", "e congregar-vos-ei de", 0) /* linha 4415 */
R(R_TEXTO, "E dar-lhes-hei coração", "E dar-lhes-ei coração", 0) /* linha 4416 */
R(R_TEXTO, "e solvendo duvidas, ao", "e solvendo dúvidas, ao", 0) /* linha 4417 */
R(R_TEXTO, "e todos o moradores de", "e todos os moradores de", 0) /* linha 4418 */
R(R_TEXTO, "eles: Porque jejuam os", "eles: Por que jejuam os", 0) /* linha 4419 */
R(R_TEXTO, "em perpetua possessão,", "em perpétua possessão,", 0) /* linha 4420 */
R(R_TEXTO, "espessura doe ramos de", "espessura dos ramos de", 0) /* linha 4421 */
R(R_TEXTO, "estrangeiros: sustem o", "estrangeiros: sustém o", 0) /* linha 4422 */
R(R_TEXTO, "família das helekitas:", "família dos helekitas:", 0) /* linha 4423 */
R(R_TEXTO, "família doa hamulitas.", "família dos hamulitas.", 0) /* linha 4424 */
R(R_TEXTO, "grade: Porque tarda em", "grade: Por que tarda em", 0) /* linha 4425 */
R(R_TEXTO, "imagem dos ciumes, que", "imagem dos ciúmes, que", 0) /* linha 4426 */
R(R_TEXTO, "incorruptível corôa de", "incorruptível coroa de", 0) /* linha 4427 */
R(R_TEXTO, "juízo das adulteras, e", "juízo das adúlteras, e", 0) /* linha 4428 */
R(R_TEXTO, "lei dos ciumes, quando", "lei dos ciúmes, quando", 0) /* linha 4429 */
R(R_TEXTO, "lei para traz das suas", "lei para trás das suas", 0) /* linha 4430 */
R(R_TEXTO, "lhes ás de fazer, para", "lhes hás de fazer, para", 0) /* linha 4431 */
R(R_TEXTO, "manjares dos ciumes da", "manjares dos ciúmes da", 0) /* linha 4432 */
R(R_TEXTO, "mãos distilavam mirra,", "mãos destilavam mirra,", 0) /* linha 4433 */
R(R_TEXTO, "mim em escorias: todos", "mim em escórias: todos", 0) /* linha 4434 */
R(R_TEXTO, "muito povo ha; faze-os", "muito povo há; faze-os", 0) /* linha 4435 */
R(R_TEXTO, "Nem tão pouco cortarás", "Nem tampouco cortarás", 0) /* linha 4436 */
R(R_TEXTO, "nem tão pouco deixarei", "nem tampouco deixarei", 0) /* linha 4437 */
R(R_TEXTO, "Nem tão pouco Ezequias", "Nem tampouco Ezequias", 0) /* linha 4438 */
R(R_TEXTO, "oferta voluntaria, mas", "oferta voluntária, mas", 0) /* linha 4439 */
R(R_TEXTO, "oferta voluntaria, sem", "oferta voluntária, sem", 0) /* linha 4440 */
R(R_TEXTO, "ordena a benção e vida", "ordena a bênção e vida", 0) /* linha 4441 */
R(R_TEXTO, "os dois capiteis sobre", "os dois capitéis sobre", 0) /* linha 4442 */
R(R_TEXTO, "pai? porque pois agora", "pai? por que pois agora", 0) /* linha 4443 */
R(R_TEXTO, "panela ao luz, põe-na,", "panela ao lume, põe-na,", 0) /* linha 4444 */
R(R_TEXTO, "para traz deles; antes", "para trás deles; antes", 0) /* linha 4445 */
R(R_TEXTO, "Peso de De uma. Dão-me", "Peso de Duma. Dão-me", 0) /* linha 4446 */
R(R_TEXTO, "Porque escreves contra", "Por que escreves contra", 0) /* linha 4447 */
R(R_TEXTO, "Porque nos rejeitarias", "Por que nos rejeitarias", 0) /* linha 4448 */
R(R_TEXTO, "Porque somos estimados", "Por que somos estimados", 0) /* linha 4449 */
R(R_TEXTO, "que ás de padecer. Eis", "que hás de padecer. Eis", 0) /* linha 4450 */
R(R_TEXTO, "que me ás de dar, pois", "que me hás de dar, pois", 0) /* linha 4451 */
R(R_TEXTO, "que neles ha, dizendo:", "que neles há, dizendo:", 0) /* linha 4452 */
R(R_TEXTO, "seu pagem de armas lhe", "seu pajem de armas lhe", 0) /* linha 4453 */
R(R_TEXTO, "seu pagem de armas que", "seu pajem de armas que", 0) /* linha 4454 */
R(R_TEXTO, "sua oferta manjares, e", "sua oferta de manjares, e", 0) /* linha 4455 */
R(R_TEXTO, "Tão pouco desapossarei", "Tampouco desapossarei", 0) /* linha 4456 */
R(R_TEXTO, "tenha preza? levantará", "tenha presa? levantará", 0) /* linha 4457 */
R(R_TEXTO, "tornar: porque pois me", "tornar: por que pois me", 0) /* linha 4458 */
R(R_TEXTO, "tornaram-se para traz.", "tornaram-se para trás.", 0) /* linha 4459 */
R(R_TEXTO, "uma corôa corruptível,", "uma coroa corruptível,", 0) /* linha 4460 */
R(R_TEXTO, "voltou-se para traz, e", "voltou-se para trás, e", 0) /* linha 4461 */
R(R_TEXTO, "à meia noite ouviu-se", "à meia-noite ouviu-se", 0) /* linha 4462 */
R(R_TEXTO, "a oração e suplica em", "a oração e súplica em", 0) /* linha 4463 */
R(R_TEXTO, "achado de aqueles que", "achado daqueles que", 0) /* linha 4464 */
R(R_TEXTO, "agora a ás de dar, e,", "agora a hás de dar, e,", 0) /* linha 4465 */
R(R_TEXTO, "Ana, porque choras? e", "Ana, por que choras? e", 0) /* linha 4466 */
R(R_TEXTO, "ao meio dia, dizendo:", "ao meio-dia, dizendo:", 0) /* linha 4467 */
R(R_TEXTO, "aquentando-se ao luz.", "aquentando-se ao lume.", 0) /* linha 4468 */
R(R_TEXTO, "assolação perpetua; o", "assolação perpétua; o", 0) /* linha 4469 */
R(R_TEXTO, "cadeira para traz, da", "cadeira para trás, da", 0) /* linha 4470 */
R(R_TEXTO, "carne vivo a na fé do", "carne vivo-a na fé do", 0) /* linha 4471 */
R(R_TEXTO, "com varias tentações.", "com várias tentações.", 0) /* linha 4472 */
R(R_TEXTO, "confusão perpetua que", "confusão perpétua que", 0) /* linha 4473 */
R(R_TEXTO, "Davi: Ha ainda alguém", "Davi: Há ainda alguém", 0) /* linha 4474 */
R(R_TEXTO, "De aqui em diante não", "Daqui em diante não", 0) /* linha 4475 */
R(R_TEXTO, "disse Jeremias: Ha. E", "disse Jeremias: Há. E", 0) /* linha 4476 */
R(R_TEXTO, "disse: Porque já três", "disse: Por que já três", 0) /* linha 4477 */
R(R_TEXTO, "disso veem ainda dois", "disso vêm ainda dois", 0) /* linha 4478 */
R(R_TEXTO, "e ao meio dia orarei;", "e ao meio-dia orarei;", 0) /* linha 4479 */
R(R_TEXTO, "e porque não comes? e", "e por que não comes? e", 0) /* linha 4480 */
R(R_TEXTO, "E porque nos fizestes", "E por que nos fizestes", 0) /* linha 4481 */
R(R_TEXTO, "e porque somente este", "e por que somente este", 0) /* linha 4482 */
R(R_TEXTO, "E porque trouxestes a", "E por que trouxestes a", 0) /* linha 4483 */
R(R_TEXTO, "e tão pouco pelejaram", "e tampouco pelejaram", 0) /* linha 4484 */
R(R_TEXTO, "esmeralda, purpura, e", "esmeralda, púrpura, e", 0) /* linha 4485 */
R(R_TEXTO, "esta suplica, estando", "esta súplica, estando", 0) /* linha 4486 */
R(R_TEXTO, "fazes as povo? por que", "fazes ao povo? por que", 0) /* linha 4487 */
R(R_TEXTO, "fazia continua oração", "fazia contínua oração", 0) /* linha 4488 */
R(R_TEXTO, "inimizade perpetua, e", "inimizade perpétua, e", 0) /* linha 4489 */
R(R_TEXTO, "Jacó um sacrificou na", "Jacó um sacrifício na", 0) /* linha 4490 */
R(R_TEXTO, "Jerusalém ha, próximo", "Jerusalém há, próximo", 0) /* linha 4491 */
R(R_TEXTO, "lâmpadas, o queimara.", "lâmpadas, o queimará.", 0) /* linha 4492 */
R(R_TEXTO, "longe doa sidônios, e", "longe dos sidônios, e", 0) /* linha 4493 */
R(R_TEXTO, "mas tem-o o marido; e", "mas tem-no o marido; e", 0) /* linha 4494 */
R(R_TEXTO, "minha suplica perante", "minha súplica perante", 0) /* linha 4495 */
R(R_TEXTO, "morte. Ha pecado para", "morte. Há pecado para", 0) /* linha 4496 */
R(R_TEXTO, "não será adultera, se", "não será adúltera, se", 0) /* linha 4497 */
R(R_TEXTO, "nem tão pouco comerei", "nem tampouco comerei", 0) /* linha 4498 */
R(R_TEXTO, "nem tão pouco desejei", "nem tampouco desejei", 0) /* linha 4499 */
R(R_TEXTO, "nem tão pouco pediste", "nem tampouco pediste", 0) /* linha 4500 */
R(R_TEXTO, "nem tão pouco segundo", "nem tampouco segundo", 0) /* linha 4501 */
R(R_TEXTO, "nenhum rei ha, grande", "nenhum rei há, grande", 0) /* linha 4502 */
R(R_TEXTO, "nos chamas te, quando", "nos chamaste, quando", 0) /* linha 4503 */
R(R_TEXTO, "oferta voluntaria, no", "oferta voluntária, no", 0) /* linha 4504 */
R(R_TEXTO, "oferta voluntaria, ou", "oferta voluntária, ou", 0) /* linha 4505 */
R(R_TEXTO, "olhou para traz dele,", "olhou para trás dele,", 0) /* linha 4506 */
R(R_TEXTO, "ou porque não ficou a", "ou por que não ficou a", 0) /* linha 4507 */
R(R_TEXTO, "por corôa gloriosa, e", "por coroa gloriosa, e", 0) /* linha 4508 */
R(R_TEXTO, "Porque se amotinam as", "Por que se amotinam as", 0) /* linha 4509 */
R(R_TEXTO, "Porque te esquecerias", "Por que te esquecerias", 0) /* linha 4510 */
R(R_TEXTO, "Porque, ó Senhor, nos", "Por que, ó Senhor, nos", 0) /* linha 4511 */
R(R_TEXTO, "Que veem estes fazer?", "Que vêm estes fazer?", 0) /* linha 4512 */
R(R_TEXTO, "querida de aquela que", "querida daquela que", 0) /* linha 4513 */
R(R_TEXTO, "respondia a si mesmo:", "respondia a si mesma:", 0) /* linha 4514 */
R(R_TEXTO, "saltérios, alaudes, e", "saltérios, alaúdes, e", 0) /* linha 4515 */
R(R_TEXTO, "Senhor todo poderoso.", "Senhor todo-poderoso.", 0) /* linha 4516 */
R(R_TEXTO, "seu pagem de armas, e", "seu pajem de armas, e", 0) /* linha 4517 */
R(R_TEXTO, "sorte de musica, para", "sorte de música, para", 0) /* linha 4518 */
R(R_TEXTO, "sua corôa, lançando-a", "sua coroa, lançando-a", 0) /* linha 4519 */
R(R_TEXTO, "também à suas tendas,", "também às suas tendas,", 0) /* linha 4520 */
R(R_TEXTO, "te constitui) perante", "te constituí) perante", 0) /* linha 4521 */
R(R_TEXTO, "tornaram para traz, e", "tornaram para trás, e", 0) /* linha 4522 */
R(R_TEXTO, "trevas nos veem; pelo", "trevas nos vêm; pelo", 0) /* linha 4523 */
R(R_TEXTO, "vestido da purpura, e", "vestido da púrpura, e", 0) /* linha 4524 */
R(R_TEXTO, "vestido de purpura, e", "vestido de púrpura, e", 0) /* linha 4525 */
R(R_TEXTO, "virá a benção do bem.", "virá a bênção do bem.", 0) /* linha 4526 */
R(R_TEXTO, "voltarão para traz os", "voltarão para trás os", 0) /* linha 4527 */
R(R_TEXTO, "a continua oferta de", "a contínua oferta de", 0) /* linha 4528 */
R(R_TEXTO, "afogava a preza para", "afogava a presa para", 0) /* linha 4529 */
R(R_TEXTO, "água; veem às cavas,", "água; vêm às cavas,", 0) /* linha 4530 */
R(R_TEXTO, "alguma de aquilo que", "alguma daquilo que", 0) /* linha 4531 */
R(R_TEXTO, "ao meio dia, perante", "ao meio-dia, perante", 0) /* linha 4532 */
R(R_TEXTO, "Barnabé à Antioquia.", "Barnabé a Antioquia.", 0) /* linha 4533 */
R(R_TEXTO, "clamarão: Ha medo de", "clamarão: Há medo de", 0) /* linha 4534 */
R(R_TEXTO, "da casa o Senhor, da", "da casa do Senhor, da", 0) /* linha 4535 */
R(R_TEXTO, "da meia noite, Paulo", "da meia-noite, Paulo", 0) /* linha 4536 */
R(R_TEXTO, "Daniel de purpura, e", "Daniel de púrpura, e", 0) /* linha 4537 */
R(R_TEXTO, "de se por o sol: Que", "de se pôr o sol: Que", 0) /* linha 4538 */
R(R_TEXTO, "de todas a bandas em", "de todas as bandas em", 0) /* linha 4539 */
R(R_TEXTO, "de varias cores, que", "de várias cores, que", 0) /* linha 4540 */
R(R_TEXTO, "do candieiro acendeu", "do candeeiro acendeu", 0) /* linha 4541 */
R(R_TEXTO, "e a benção do Senhor", "e a bênção do Senhor", 0) /* linha 4542 */
R(R_TEXTO, "e ante ontem, quando", "e anteontem, quando", 0) /* linha 4543 */
R(R_TEXTO, "e mostrar-te-hei que", "e mostrar-te-ei que", 0) /* linha 4544 */
R(R_TEXTO, "eis que veem dias, e", "eis que vêm dias, e", 0) /* linha 4545 */
R(R_TEXTO, "eles veem a ti, como", "eles vêm a ti, como", 0) /* linha 4546 */
R(R_TEXTO, "em varias tentações:", "em várias tentações:", 0) /* linha 4547 */
R(R_TEXTO, "Então os Cabeças dos", "Então os cabeças dos", 0) /* linha 4548 */
R(R_TEXTO, "espiritual. Ha corpo", "espiritual. Há corpo", 0) /* linha 4549 */
R(R_TEXTO, "filhos do Israel não", "filhos de Israel não", 0) /* linha 4550 */
R(R_TEXTO, "justiça ha-de julgar", "justiça há de julgar", 0) /* linha 4551 */
R(R_TEXTO, "Mas, quanto tu deres", "Mas, quando tu deres", 0) /* linha 4552 */
R(R_TEXTO, "minha suplica diante", "minha súplica diante", 0) /* linha 4553 */
R(R_TEXTO, "mulher adultera que,", "mulher adúltera que,", 0) /* linha 4554 */
R(R_TEXTO, "mulher adultera: ela", "mulher adúltera: ela", 0) /* linha 4555 */
R(R_TEXTO, "na mão e Acabe, para", "na mão de Acabe, para", 0) /* linha 4556 */
R(R_TEXTO, "nem tão pouco devias", "nem tampouco devias", 0) /* linha 4557 */
R(R_TEXTO, "nem tão pouco olhará", "nem tampouco olhará", 0) /* linha 4558 */
R(R_TEXTO, "nem tão pouco passes", "nem tampouco passes", 0) /* linha 4559 */
R(R_TEXTO, "nós fossemos fracos,", "nós fôssemos fracos,", 0) /* linha 4560 */
R(R_TEXTO, "nós? porque pois nos", "nós? por que pois nos", 0) /* linha 4561 */
R(R_TEXTO, "nossa suplica diante", "nossa súplica diante", 0) /* linha 4562 */
R(R_TEXTO, "o ouriço cacheiro, e", "o ouriço-cacheiro, e", 0) /* linha 4563 */
R(R_TEXTO, "olharão para traz: e", "olharão para trás: e", 0) /* linha 4564 */
R(R_TEXTO, "onde teus ungido uma", "onde tens ungido uma", 0) /* linha 4565 */
R(R_TEXTO, "por oferta pacifica;", "por oferta pacífica;", 0) /* linha 4566 */
R(R_TEXTO, "Porque pois dizes, ó", "Por que pois dizes, ó", 0) /* linha 4567 */
R(R_TEXTO, "Porque te arrebata o", "Por que te arrebata o", 0) /* linha 4568 */
R(R_TEXTO, "povo em os olhos dos", "povo nos olhos dos", 0) /* linha 4569 */
R(R_TEXTO, "que hei-de herdá-la?", "que hei de herdá-la?", 0) /* linha 4570 */
R(R_TEXTO, "que, no non o ano do", "que, no nono ano do", 0) /* linha 4571 */
R(R_TEXTO, "saltérios, alaudes e", "saltérios, alaúdes e", 0) /* linha 4572 */
R(R_TEXTO, "sarna em os magos, e", "sarna nos magos, e", 0) /* linha 4573 */
R(R_TEXTO, "Saul para traz, Davi", "Saul para trás, Davi", 0) /* linha 4574 */
R(R_TEXTO, "se voltou para traz.", "se voltou para trás.", 0) /* linha 4575 */
R(R_TEXTO, "sorte de musica, vos", "sorte de música, vos", 0) /* linha 4576 */
R(R_TEXTO, "também eu disso: Não", "também eu disse: Não", 0) /* linha 4577 */
R(R_TEXTO, "Tão pouco apliques o", "Tampouco apliques o", 0) /* linha 4578 */
R(R_TEXTO, "tarde de aquele dia,", "tarde daquele dia,", 0) /* linha 4579 */
R(R_TEXTO, "torno para traz, não", "torno para trás, não", 0) /* linha 4580 */
R(R_TEXTO, "tu me ás amado antes", "tu me hás amado antes", 0) /* linha 4581 */
R(R_TEXTO, "Vira-te para traz de", "Vira-te para trás de", 0) /* linha 4582 */
R(R_TEXTO, "vossa suplica diante", "vossa súplica diante", 0) /* linha 4583 */
R(R_TEXTO, "ao meio dia; porque", "ao meio-dia; porque", 0) /* linha 4584 */
R(R_TEXTO, "aos seus Cabeças, e", "aos seus cabeças, e", 0) /* linha 4585 */
R(R_TEXTO, "coisas moveis, como", "coisas móveis, como", 0) /* linha 4586 */
R(R_TEXTO, "com alaudes, harpas", "com alaúdes, harpas", 0) /* linha 4587 */
R(R_TEXTO, "Cornélio: Ha quatro", "Cornélio: Há quatro", 0) /* linha 4588 */
R(R_TEXTO, "daquela benção, com", "daquela bênção, com", 0) /* linha 4589 */
R(R_TEXTO, "Deus: os Cabeças de", "Deus: os cabeças de", 0) /* linha 4590 */
R(R_TEXTO, "dirá: Pois porque o", "dirá: Pois por que o", 0) /* linha 4591 */
R(R_TEXTO, "disse: Ha paz, Jeú?", "disse: Há paz, Jeú?", 0) /* linha 4592 */
R(R_TEXTO, "disse: O néscios, e", "disse: Ó néscios, e", 0) /* linha 4593 */
R(R_TEXTO, "e a preza do tirano", "e a presa do tirano", 0) /* linha 4594 */
R(R_TEXTO, "e alaudes, tamboris", "e alaúdes, tamboris", 0) /* linha 4595 */
R(R_TEXTO, "e apiedar-me-hei de", "e apiedar-me-ei de", 0) /* linha 4596 */
R(R_TEXTO, "e ir-me-hei embora;", "e ir-me-ei embora;", 0) /* linha 4597 */
R(R_TEXTO, "E livrar-te-hei das", "E livrar-te-ei das", 0) /* linha 4598 */
R(R_TEXTO, "e mostrar-te-hei as", "e mostrar-te-ei as", 0) /* linha 4599 */
R(R_TEXTO, "e o seus estatutos,", "e os seus estatutos,", 0) /* linha 4600 */
R(R_TEXTO, "E porque atentas tu", "E por que atentas tu", 0) /* linha 4601 */
R(R_TEXTO, "E porque reparas tu", "E por que reparas tu", 0) /* linha 4602 */
R(R_TEXTO, "e varias maravilhas", "e várias maravilhas", 0) /* linha 4603 */
R(R_TEXTO, "enchia de prezas as", "enchia de presas as", 0) /* linha 4604 */
R(R_TEXTO, "estas bençãos virão", "estas bênçãos virão", 0) /* linha 4605 */
R(R_TEXTO, "falta nelas ha; não", "falta nelas há; não", 0) /* linha 4606 */
R(R_TEXTO, "fino e purpura, e a", "fino e púrpura, e a", 0) /* linha 4607 */
R(R_TEXTO, "foste prospera, até", "foste próspera, até", 0) /* linha 4608 */
R(R_TEXTO, "Ha acaso iniquidade", "Há acaso iniquidade", 0) /* linha 4609 */
R(R_TEXTO, "imagem de ciumes na", "imagem de ciúmes na", 0) /* linha 4610 */
R(R_TEXTO, "mas tem-o a mulher.", "mas tem-no a mulher.", 0) /* linha 4611 */
R(R_TEXTO, "mim cara trazeres à", "mim para trazeres à", 0) /* linha 4612 */
R(R_TEXTO, "nem tão pouco ainda", "nem tampouco ainda", 0) /* linha 4613 */
R(R_TEXTO, "nem tão pouco desde", "nem tampouco desde", 0) /* linha 4614 */
R(R_TEXTO, "nem tão pouco foste", "nem tampouco foste", 0) /* linha 4615 */
R(R_TEXTO, "Nem tão pouco podem", "Nem tampouco podem", 0) /* linha 4616 */
R(R_TEXTO, "nem tão pouco sabem", "nem tampouco sabem", 0) /* linha 4617 */
R(R_TEXTO, "olhos, dar-te-hei a", "olhos, dar-te-ei a", 0) /* linha 4618 */
R(R_TEXTO, "os meus moveis, que", "os meus móveis, que", 0) /* linha 4619 */
R(R_TEXTO, "para que pára sobre", "para que para sobre", 0) /* linha 4620 */
R(R_TEXTO, "Pilatos: Eis-aqui o", "Pilatos: Eis aqui o", 0) /* linha 4621 */
R(R_TEXTO, "Pois que? Pecaremos", "Pois quê? Pecaremos", 0) /* linha 4622 */
R(R_TEXTO, "Porque não me matou", "Por que não me matou", 0) /* linha 4623 */
R(R_TEXTO, "Porque se tiraria o", "Por que se tiraria o", 0) /* linha 4624 */
R(R_TEXTO, "possessão perpetua.", "possessão perpétua.", 0) /* linha 4625 */
R(R_TEXTO, "postos por preza, e", "postos por presa, e", 0) /* linha 4626 */
R(R_TEXTO, "que veem sete anos,", "que vêm sete anos,", 0) /* linha 4627 */
R(R_TEXTO, "que, em o que falam", "que, no que falam", 0) /* linha 4628 */
R(R_TEXTO, "real azul celeste e", "real azul-celeste e", 0) /* linha 4629 */
R(R_TEXTO, "retirou para traz a", "retirou para trás a", 0) /* linha 4630 */
R(R_TEXTO, "retirou para traz o", "retirou para trás o", 0) /* linha 4631 */
R(R_TEXTO, "seu pagem de armas.", "seu pajem de armas.", 0) /* linha 4632 */
R(R_TEXTO, "seus capiteis assim", "seus capitéis assim", 0) /* linha 4633 */
R(R_TEXTO, "sorte de musica, se", "sorte de música, se", 0) /* linha 4634 */
R(R_TEXTO, "também à requerido.", "também é requerido.", 0) /* linha 4635 */
R(R_TEXTO, "todas as dizimas de", "todas as dízimas de", 0) /* linha 4636 */
R(R_TEXTO, "todas as dizimas do", "todas as dízimas do", 0) /* linha 4637 */
R(R_TEXTO, "tua benção. (Selá).", "tua bênção. (Selá).", 0) /* linha 4638 */
R(R_TEXTO, "uma mulher sabia, e", "uma mulher sábia, e", 0) /* linha 4639 */
R(R_TEXTO, "vejo? E o homens da", "vejo? E os homens da", 0) /* linha 4640 */
R(R_TEXTO, "voltaram para traz.", "voltaram para trás.", 0) /* linha 4641 */
R(R_TEXTO, "voltaste para traz?", "voltaste para trás?", 0) /* linha 4642 */
R(R_TEXTO, "vos constitui, para", "vos constituí, para", 0) /* linha 4643 */
R(R_TEXTO, "a corôa; deram-lhe", "a coroa; deram-lhe", 0) /* linha 4644 */
R(R_TEXTO, "à preza, moabitas!", "à presa, moabitas!", 0) /* linha 4645 */
R(R_TEXTO, "a sua preza, ainda", "a sua presa, ainda", 0) /* linha 4646 */
R(R_TEXTO, "Achis: Porque? que", "Achis: Por quê? que", 0) /* linha 4647 */
R(R_TEXTO, "Arnom; eis-aqui na", "Arnom; eis aqui na", 0) /* linha 4648 */
R(R_TEXTO, "bem? porque veio a", "bem? por que veio a", 0) /* linha 4649 */
R(R_TEXTO, "caiam para traz, e", "caiam para trás, e", 0) /* linha 4650 */
R(R_TEXTO, "cobre era forma de", "cobre em forma de", 0) /* linha 4651 */
R(R_TEXTO, "com alaudes, sobre", "com alaúdes, sobre", 0) /* linha 4652 */
R(R_TEXTO, "coração para traz.", "coração para trás.", 0) /* linha 4653 */
R(R_TEXTO, "de duas dizimas de", "de duas dízimas de", 0) /* linha 4654 */
R(R_TEXTO, "de varias cores, e", "de várias cores, e", 0) /* linha 4655 */
R(R_TEXTO, "disse: Que ha, que", "disse: Que há, que", 0) /* linha 4656 */
R(R_TEXTO, "disse: Tão pouco a", "disse: Tampouco a", 0) /* linha 4657 */
R(R_TEXTO, "disseram: E réu de", "disseram: É réu de", 0) /* linha 4658 */
R(R_TEXTO, "disserem: Ha paz e", "disserem: Há paz e", 0) /* linha 4659 */
R(R_TEXTO, "doutrinas varias e", "doutrinas várias e", 0) /* linha 4660 */
R(R_TEXTO, "e de num testifica", "e de mim testifica", 0) /* linha 4661 */
R(R_TEXTO, "e de purpura, e de", "e de púrpura, e de", 0) /* linha 4662 */
R(R_TEXTO, "e ensinar-te-hei a", "e ensinar-te-ei a", 0) /* linha 4663 */
R(R_TEXTO, "e mostrar-te-hei o", "e mostrar-te-ei o", 0) /* linha 4664 */
R(R_TEXTO, "E o senhor dissera", "E o Senhor dissera", 0) /* linha 4665 */
R(R_TEXTO, "e porque acenam os", "e por que acenam os", 0) /* linha 4666 */
R(R_TEXTO, "Eis-aqui, bendizei", "Eis aqui, bendizei", 0) /* linha 4667 */
R(R_TEXTO, "entre as prezas, e", "entre as presas, e", 0) /* linha 4668 */
R(R_TEXTO, "era Cabeça da casa", "era cabeça da casa", 0) /* linha 4669 */
R(R_TEXTO, "escarnecer de nim;", "escarnecer de mim;", 0) /* linha 4670 */
R(R_TEXTO, "falta nele ha; não", "falta nele há; não", 0) /* linha 4671 */
R(R_TEXTO, "geração adultera e", "geração adúltera e", 0) /* linha 4672 */
R(R_TEXTO, "Ha diferença entre", "Há diferença entre", 0) /* linha 4673 */
R(R_TEXTO, "jornadas ha, desde", "jornadas há, desde", 0) /* linha 4674 */
R(R_TEXTO, "mas nenhumas ha, e", "mas nenhumas há, e", 0) /* linha 4675 */
R(R_TEXTO, "meio doe filhos de", "meio dos filhos de", 0) /* linha 4676 */
R(R_TEXTO, "meu bem querido da", "meu bem-querido da", 0) /* linha 4677 */
R(R_TEXTO, "minha benção. Mais", "minha bênção. Mais", 0) /* linha 4678 */
R(R_TEXTO, "moinhos o moia, ou", "moinhos o moía, ou", 0) /* linha 4679 */
R(R_TEXTO, "mulheres sabias de", "mulheres sábias de", 0) /* linha 4680 */
R(R_TEXTO, "não me exército em", "não me exercito em", 0) /* linha 4681 */
R(R_TEXTO, "nem tão pouco diga", "nem tampouco diga", 0) /* linha 4682 */
R(R_TEXTO, "Nem tão pouco está", "Nem tampouco está", 0) /* linha 4683 */
R(R_TEXTO, "nem tão pouco para", "nem tampouco para", 0) /* linha 4684 */
R(R_TEXTO, "o corvo marinho, e", "o corvo-marinho, e", 0) /* linha 4685 */
R(R_TEXTO, "oferta pacifica se", "oferta pacífica se", 0) /* linha 4686 */
R(R_TEXTO, "oferta pacifica, o", "oferta pacífica, o", 0) /* linha 4687 */
R(R_TEXTO, "oferta voluntaria.", "oferta voluntária.", 0) /* linha 4688 */
R(R_TEXTO, "olhar para traz de", "olhar para trás de", 0) /* linha 4689 */
R(R_TEXTO, "olhes para traz de", "olhes para trás de", 0) /* linha 4690 */
R(R_TEXTO, "os seus Cabeças, e", "os seus cabeças, e", 0) /* linha 4691 */
R(R_TEXTO, "pão nem água ha: e", "pão nem água há: e", 0) /* linha 4692 */
R(R_TEXTO, "para as as aldeias", "para as aldeias", 0) /* linha 4693 */
R(R_TEXTO, "pela meia noite, o", "pela meia-noite, o", 0) /* linha 4694 */
R(R_TEXTO, "Pois que? julga-se", "Pois quê? julga-se", 0) /* linha 4695 */
R(R_TEXTO, "Porque dais coices", "Por que dais coices", 0) /* linha 4696 */
R(R_TEXTO, "Porque serias como", "Por que serias como", 0) /* linha 4697 */
R(R_TEXTO, "quanto nela ha; os", "quanto nela há; os", 0) /* linha 4698 */
R(R_TEXTO, "quanto neles ha, e", "quanto neles há, e", 0) /* linha 4699 */
R(R_TEXTO, "que ás de livrar a", "que hás de livrar a", 0) /* linha 4700 */
R(R_TEXTO, "que ás de vir, que", "que hás de vir, que", 0) /* linha 4701 */
R(R_TEXTO, "que profetiza vos?", "que vos profetiza?", 0) /* linha 4702 */
R(R_TEXTO, "que veem do norte:", "que vêm do norte:", 0) /* linha 4703 */
R(R_TEXTO, "sua suplica diante", "sua súplica diante", 0) /* linha 4704 */
R(R_TEXTO, "terra de Benjamin:", "terra de Benjamim:", 0) /* linha 4705 */
R(R_TEXTO, "vigias veem de uma", "vigias vêm de uma", 0) /* linha 4706 */
R(R_TEXTO, "voltem para traz e", "voltem para trás e", 0) /* linha 4707 */
R(R_TEXTO, "à meia noite, que", "à meia-noite, que", 0) /* linha 4708 */
R(R_TEXTO, "Acaso não veem de", "Acaso não vêm de", 0) /* linha 4709 */
R(R_TEXTO, "anos, que veem, e", "anos, que vêm, e", 0) /* linha 4710 */
R(R_TEXTO, "ao meio dia andem", "ao meio-dia andem", 0) /* linha 4711 */
R(R_TEXTO, "ao meio dia Elias", "ao meio-dia Elias", 0) /* linha 4712 */
R(R_TEXTO, "ao meio dia, como", "ao meio-dia, como", 0) /* linha 4713 */
R(R_TEXTO, "céu o os consuma,", "céu e os consuma,", 0) /* linha 4714 */
R(R_TEXTO, "comerá a preza, e", "comerá a presa, e", 0) /* linha 4715 */
R(R_TEXTO, "crê em Ele, tenha", "crê nele, tenha", 0) /* linha 4716 */
R(R_TEXTO, "da preza subiste,", "da presa subiste,", 0) /* linha 4717 */
R(R_TEXTO, "de varias doenças", "de várias doenças", 0) /* linha 4718 */
R(R_TEXTO, "dia, era que eles", "dia, em que eles", 0) /* linha 4719 */
R(R_TEXTO, "disse: Eis-aqui o", "disse: Eis aqui o", 0) /* linha 4720 */
R(R_TEXTO, "e aos Cabeças dos", "e aos cabeças dos", 0) /* linha 4721 */
R(R_TEXTO, "e dar-te-hei dois", "e dar-te-ei dois", 0) /* linha 4722 */
R(R_TEXTO, "e far-te-hei bem;", "e far-te-ei bem;", 0) /* linha 4723 */
R(R_TEXTO, "e ir-me-hei; pois", "e ir-me-ei; pois", 0) /* linha 4724 */
R(R_TEXTO, "e porque está mal", "e por que está mal", 0) /* linha 4725 */
R(R_TEXTO, "E porque o Senhor", "E por que o Senhor", 0) /* linha 4726 */
R(R_TEXTO, "e tão pouco fazem", "e tampouco fazem", 0) /* linha 4727 */
R(R_TEXTO, "e tiver ciumes de", "e tiver ciúmes de", 0) /* linha 4728 */
R(R_TEXTO, "e tornar-me-hei a", "e tornar-me-ei a", 0) /* linha 4729 */
R(R_TEXTO, "e varias abluções", "e várias abluções", 0) /* linha 4730 */
R(R_TEXTO, "e veem descendo e", "e vêm descendo e", 0) /* linha 4731 */
R(R_TEXTO, "é): Ha conselho e", "é): Há conselho e", 0) /* linha 4732 */
R(R_TEXTO, "ele para traz, os", "ele para trás, os", 0) /* linha 4733 */
R(R_TEXTO, "Esaú; o filhos de", "Esaú; os filhos de", 0) /* linha 4734 */
R(R_TEXTO, "Hamã: Tão pouco a", "Hamã: Tampouco a", 0) /* linha 4735 */
R(R_TEXTO, "hoje tomastes tão", "hoje tornastes tão", 0) /* linha 4736 */
R(R_TEXTO, "mão sobro os teus", "mão sobre os teus", 0) /* linha 4737 */
R(R_TEXTO, "mas benção haverá", "mas bênção haverá", 0) /* linha 4738 */
R(R_TEXTO, "minha benção, que", "minha bênção, que", 0) /* linha 4739 */
R(R_TEXTO, "nem tão pouco meu", "nem tampouco meu", 0) /* linha 4740 */
R(R_TEXTO, "Nem tão pouco vos", "Nem tampouco vos", 0) /* linha 4741 */
R(R_TEXTO, "nós e ministrada:", "nós é ministrada:", 0) /* linha 4742 */
R(R_TEXTO, "nuvens distilam o", "nuvens destilam o", 0) /* linha 4743 */
R(R_TEXTO, "o laço veem sobre", "o laço vêm sobre", 0) /* linha 4744 */
R(R_TEXTO, "o meio dia; ainda", "o meio-dia; ainda", 0) /* linha 4745 */
R(R_TEXTO, "olhará para traz.", "olhará para trás.", 0) /* linha 4746 */
R(R_TEXTO, "ouvi: Quem ha, de", "ouvi: Quem há, de", 0) /* linha 4747 */
R(R_TEXTO, "para traz, fez-me", "para trás, fez-me", 0) /* linha 4748 */
R(R_TEXTO, "para traz: terror", "para trás: terror", 0) /* linha 4749 */
R(R_TEXTO, "pomba, a verse as", "pomba, a ver se as", 0) /* linha 4750 */
R(R_TEXTO, "porém sabias, bem", "porém sábias, bem", 0) /* linha 4751 */
R(R_TEXTO, "Porque blasfema o", "Por que blasfema o", 0) /* linha 4752 */
R(R_TEXTO, "Porque ciumes são", "Porque ciúmes são", 0) /* linha 4753 */
R(R_TEXTO, "Porque enfeitas o", "Por que enfeitas o", 0) /* linha 4754 */
R(R_TEXTO, "Porque escondes a", "Por que escondes a", 0) /* linha 4755 */
R(R_TEXTO, "Porque escondes o", "Por que escondes o", 0) /* linha 4756 */
R(R_TEXTO, "Porque ficaste tu", "Por que ficaste tu", 0) /* linha 4757 */
R(R_TEXTO, "provoca a ciumes.", "provoca a ciúmes.", 0) /* linha 4758 */
R(R_TEXTO, "que hei-de fazer,", "que hei de fazer,", 0) /* linha 4759 */
R(R_TEXTO, "que veem para vós", "que vêm para vós", 0) /* linha 4760 */
R(R_TEXTO, "que vo-lo o tenho", "que vo-lo tenho", 0) /* linha 4761 */
R(R_TEXTO, "retiro para traz.", "retiro para trás.", 0) /* linha 4762 */
R(R_TEXTO, "Se ás de livrar a", "Se hás de livrar a", 0) /* linha 4763 */
R(R_TEXTO, "Senhor: Se-não me", "Senhor: Se não me", 0) /* linha 4764 */
R(R_TEXTO, "Tão pouco expeliu", "Tampouco expeliu", 0) /* linha 4765 */
R(R_TEXTO, "Tão pouco Naftali", "Tampouco Naftali", 0) /* linha 4766 */
R(R_TEXTO, "tornar para traz?", "tornar para trás?", 0) /* linha 4767 */
R(R_TEXTO, "Tu me ás de dar a", "Tu me hás de dar a", 0) /* linha 4768 */
R(R_TEXTO, "vossas bençãos; e", "vossas bênçãos; e", 0) /* linha 4769 */
R(R_TEXTO, "A benção, quando", "A bênção, quando", 0) /* linha 4770 */
R(R_TEXTO, "à meia noite, se", "à meia-noite, se", 0) /* linha 4771 */
R(R_TEXTO, "a preza daqueles", "a presa daqueles", 0) /* linha 4772 */
R(R_TEXTO, "como o meio dia.", "como o meio-dia.", 0) /* linha 4773 */
R(R_TEXTO, "da Media; porque", "da Média; porque", 0) /* linha 4774 */
R(R_TEXTO, "de duas dizimas.", "de duas dízimas.", 0) /* linha 4775 */
R(R_TEXTO, "de obra prima se", "de obra-prima se", 0) /* linha 4776 */
R(R_TEXTO, "de varias cores.", "de várias cores.", 0) /* linha 4777 */
R(R_TEXTO, "de varias cores;", "de várias cores;", 0) /* linha 4778 */
R(R_TEXTO, "dois capiteis de", "dois capitéis de", 0) /* linha 4779 */
R(R_TEXTO, "e a purpura, e o", "e a púrpura, e o", 0) /* linha 4780 */
R(R_TEXTO, "e adulteras, não", "e adúlteras, não", 0) /* linha 4781 */
R(R_TEXTO, "e espantai vos e", "e espantai-vos e", 0) /* linha 4782 */
R(R_TEXTO, "E far-te-hei uma", "E far-te-ei uma", 0) /* linha 4783 */
R(R_TEXTO, "e não o ha; pela", "e não o há; pela", 0) /* linha 4784 */
R(R_TEXTO, "é obra prima dos", "é obra-prima dos", 0) /* linha 4785 */
R(R_TEXTO, "e os Cabeças dos", "e os cabeças dos", 0) /* linha 4786 */
R(R_TEXTO, "e tão pouco aqui", "e tampouco aqui", 0) /* linha 4787 */
R(R_TEXTO, "e tão pouco está", "e tampouco está", 0) /* linha 4788 */
R(R_TEXTO, "ele para traz de", "ele para trás de", 0) /* linha 4789 */
R(R_TEXTO, "então morrera só", "então morrerá só", 0) /* linha 4790 */
R(R_TEXTO, "ferida me doe, e", "ferida me dói, e", 0) /* linha 4791 */
R(R_TEXTO, "fiéis bençãos de", "fiéis bênçãos de", 0) /* linha 4792 */
R(R_TEXTO, "foram cito mil e", "foram oito mil e", 0) /* linha 4793 */
R(R_TEXTO, "grande ao luz, e", "grande ao lume, e", 0) /* linha 4794 */
R(R_TEXTO, "homem a hora que", "homem à hora que", 0) /* linha 4795 */
R(R_TEXTO, "laço, veem sobre", "laço, vêm sobre", 0) /* linha 4796 */
R(R_TEXTO, "minha suplica; o", "minha súplica; o", 0) /* linha 4797 */
R(R_TEXTO, "não ás mister de", "não hás mister de", 0) /* linha 4798 */
R(R_TEXTO, "Nem tão pouco eu", "Nem tampouco eu", 0) /* linha 4799 */
R(R_TEXTO, "nem tão pouco os", "nem tampouco os", 0) /* linha 4800 */
R(R_TEXTO, "Nem tão pouco os", "Nem tampouco os", 0) /* linha 4801 */
R(R_TEXTO, "oferta pacifica.", "oferta pacífica.", 0) /* linha 4802 */
R(R_TEXTO, "Os capiteis pois", "Os capitéis pois", 0) /* linha 4803 */
R(R_TEXTO, "por sabias, para", "por sábias, para", 0) /* linha 4804 */
R(R_TEXTO, "Porque lhe ás de", "Porque lhe hás de", 0) /* linha 4805 */
R(R_TEXTO, "proveito ha, mas", "proveito há, mas", 0) /* linha 4806 */
R(R_TEXTO, "que ás de comer,", "que hás de comer,", 0) /* linha 4807 */
R(R_TEXTO, "que ás de falar.", "que hás de falar.", 0) /* linha 4808 */
R(R_TEXTO, "que ás de fazer,", "que hás de fazer,", 0) /* linha 4809 */
R(R_TEXTO, "que ás de fazer.", "que hás de fazer.", 0) /* linha 4810 */
R(R_TEXTO, "que ás de fazer;", "que hás de fazer;", 0) /* linha 4811 */
R(R_TEXTO, "que veem as aves", "que vêm as aves", 0) /* linha 4812 */
R(R_TEXTO, "que veem dias em", "que vêm dias em", 0) /* linha 4813 */
R(R_TEXTO, "quem há e ir por", "quem há de ir por", 0) /* linha 4814 */
R(R_TEXTO, "Senhor sustem os", "Senhor sustém os", 0) /* linha 4815 */
R(R_TEXTO, "será prospera, a", "será próspera, a", 0) /* linha 4816 */
R(R_TEXTO, "suave musica não", "suave música não", 0) /* linha 4817 */
R(R_TEXTO, "Tão pouco pequei", "Tampouco pequei", 0) /* linha 4818 */
R(R_TEXTO, "terra sera cheia", "terra será cheia", 0) /* linha 4819 */
R(R_TEXTO, "tu ás de enviar.", "tu hás de enviar.", 0) /* linha 4820 */
R(R_TEXTO, "tuas escorias; e", "tuas escórias; e", 0) /* linha 4821 */
R(R_TEXTO, "um os Cabeças do", "um os cabeças do", 0) /* linha 4822 */
R(R_TEXTO, "volte para traz.", "volte para trás.", 0) /* linha 4823 */
R(R_TEXTO, "vós a benção e a", "vós a bênção e a", 0) /* linha 4824 */
R(R_TEXTO, "À cerca do qual", "Acerca do qual", 0) /* linha 4825 */
R(R_TEXTO, "À meia noite eu", "À meia-noite eu", 0) /* linha 4826 */
R(R_TEXTO, "À meia noite me", "À meia-noite me", 0) /* linha 4827 */
R(R_TEXTO, "à meia noite os", "à meia-noite os", 0) /* linha 4828 */
R(R_TEXTO, "à meia noite, e", "à meia-noite, e", 0) /* linha 4829 */
R(R_TEXTO, "Acaso ha, entre", "Acaso há, entre", 0) /* linha 4830 */
R(R_TEXTO, "ao meio dia, de", "ao meio-dia, de", 0) /* linha 4831 */
R(R_TEXTO, "aquela corôa, e", "aquela coroa, e", 0) /* linha 4832 */
R(R_TEXTO, "das adulteras e", "das adúlteras e", 0) /* linha 4833 */
R(R_TEXTO, "de preza: todos", "de presa: todos", 0) /* linha 4834 */
R(R_TEXTO, "de purpura, que", "de púrpura, que", 0) /* linha 4835 */
R(R_TEXTO, "de seu pais: em", "de seus pais: em", 0) /* linha 4836 */
R(R_TEXTO, "disse: Com que?", "disse: Com quê?", 0) /* linha 4837 */
R(R_TEXTO, "do bode vive, e", "do bode vivo, e", 0) /* linha 4838 */
R(R_TEXTO, "do candieiro de", "do candeeiro de", 0) /* linha 4839 */
R(R_TEXTO, "dons aos homem.", "dons aos homens.", 0) /* linha 4840 */
R(R_TEXTO, "e à tuas casas;", "e às tuas casas;", 0) /* linha 4841 */
R(R_TEXTO, "e adultera pede", "e adúltera pede", 0) /* linha 4842 */
R(R_TEXTO, "E constitui ali", "E constituí ali", 0) /* linha 4843 */
R(R_TEXTO, "e dar-te-hei um", "e dar-te-ei um", 0) /* linha 4844 */
R(R_TEXTO, "e diminui a tua", "e diminuí a tua", 0) /* linha 4845 */
R(R_TEXTO, "é mais sabia do", "é mais sábia do", 0) /* linha 4846 */
R(R_TEXTO, "e purpura; obra", "e púrpura; obra", 0) /* linha 4847 */
R(R_TEXTO, "e tão pouco vos", "e tampouco vos", 0) /* linha 4848 */
R(R_TEXTO, "e te glórias em", "e te glorias em", 0) /* linha 4849 */
R(R_TEXTO, "Egito sustem, e", "Egito sustêm, e", 0) /* linha 4850 */
R(R_TEXTO, "em bençãos, mas", "em bênçãos, mas", 0) /* linha 4851 */
R(R_TEXTO, "fazia, veem ter", "fazia, vêm ter", 0) /* linha 4852 */
R(R_TEXTO, "fino nela ha, o", "fino nela há, o", 0) /* linha 4853 */
R(R_TEXTO, "grande corôa de", "grande coroa de", 0) /* linha 4854 */
R(R_TEXTO, "Ha alguma coisa", "Há alguma coisa", 0) /* linha 4855 */
R(R_TEXTO, "há benção nele;", "há bênção nele;", 0) /* linha 4856 */
R(R_TEXTO, "lugar a cima de", "lugar acima de", 0) /* linha 4857 */
R(R_TEXTO, "lugar e este; e", "lugar a este; e", 0) /* linha 4858 */
R(R_TEXTO, "luz perpetua, e", "luz perpétua, e", 0) /* linha 4859 */
R(R_TEXTO, "mais sabias das", "mais sábias das", 0) /* linha 4860 */
R(R_TEXTO, "não ás de dizer", "não hás de dizer", 0) /* linha 4861 */
R(R_TEXTO, "Nem tão pouco é", "Nem tampouco é", 0) /* linha 4862 */
R(R_TEXTO, "nem tão pouco o", "nem tampouco o", 0) /* linha 4863 */
R(R_TEXTO, "ou ao janela, e", "ou à janela, e", 0) /* linha 4864 */
R(R_TEXTO, "Pai, possui por", "Pai, possuí por", 0) /* linha 4865 */
R(R_TEXTO, "Pela benção dos", "Pela bênção dos", 0) /* linha 4866 */
R(R_TEXTO, "Pois que? Somos", "Pois quê? Somos", 0) /* linha 4867 */
R(R_TEXTO, "por corações se", "por caracóis se", 0) /* linha 4868 */
R(R_TEXTO, "por preza, como", "por presa, como", 0) /* linha 4869 */
R(R_TEXTO, "porém não a ha.", "porém não a há.", 0) /* linha 4870 */
R(R_TEXTO, "porque ás de ir", "porque hás de ir", 0) /* linha 4871 */
R(R_TEXTO, "Porque dirão as", "Por que dirão as", 0) /* linha 4872 */
R(R_TEXTO, "Porque estás ao", "Por que estás ao", 0) /* linha 4873 */
R(R_TEXTO, "que ás de fazer", "que hás de fazer", 0) /* linha 4874 */
R(R_TEXTO, "que distilem os", "que destilem os", 0) /* linha 4875 */
R(R_TEXTO, "que em ti ha, a", "que em ti há, a", 0) /* linha 4876 */
R(R_TEXTO, "que nela ha, se", "que nela há, se", 0) /* linha 4877 */
R(R_TEXTO, "que nele ha, no", "que nele há, no", 0) /* linha 4878 */
R(R_TEXTO, "que neles ha, e", "que neles há, e", 0) /* linha 4879 */
R(R_TEXTO, "sairdes de ali.", "sairdes dali.", 0) /* linha 4880 */
R(R_TEXTO, "sua injuria com", "sua injúria com", 0) /* linha 4881 */
R(R_TEXTO, "temor ha, porém", "temor há, porém", 0) /* linha 4882 */
R(R_TEXTO, "ti, a Benjamin.", "ti, a Benjamim.", 0) /* linha 4883 */
R(R_TEXTO, "tirava a preza.", "tirava a presa.", 0) /* linha 4884 */
R(R_TEXTO, "três dizimas de", "três dízimas de", 0) /* linha 4885 */
R(R_TEXTO, "tua benção será", "tua bênção será", 0) /* linha 4886 */
R(R_TEXTO, "tua suplica que", "tua súplica que", 0) /* linha 4887 */
R(R_TEXTO, "uma benção: não", "uma bênção: não", 0) /* linha 4888 */
R(R_TEXTO, "Veem contra mim", "Vêm contra mim", 0) /* linha 4889 */
R(R_TEXTO, "verdade em nos.", "verdade em nós.", 0) /* linha 4890 */
R(R_TEXTO, "a corôa deste,", "a coroa deste,", 0) /* linha 4891 */
R(R_TEXTO, "a suplica, que", "a súplica, que", 0) /* linha 4892 */
R(R_TEXTO, "a tua preza, e", "a tua presa, e", 0) /* linha 4893 */
R(R_TEXTO, "alguns ha, dos", "alguns há, dos", 0) /* linha 4894 */
R(R_TEXTO, "ao meio dia um", "ao meio-dia um", 0) /* linha 4895 */
R(R_TEXTO, "ao meio dia, e", "ao meio-dia, e", 0) /* linha 4896 */
R(R_TEXTO, "Ao meio dia, ó", "Ao meio-dia, ó", 0) /* linha 4897 */
R(R_TEXTO, "ao meio dia: e", "ao meio-dia: e", 0) /* linha 4898 */
R(R_TEXTO, "as escorias, e", "as escórias, e", 0) /* linha 4899 */
R(R_TEXTO, "com alaudes, e", "com alaúdes, e", 0) /* linha 4900 */
R(R_TEXTO, "da corôa serão", "da coroa serão", 0) /* linha 4901 */
R(R_TEXTO, "da Media dirão", "da Média dirão", 0) /* linha 4902 */
R(R_TEXTO, "das bençãos de", "das bênçãos de", 0) /* linha 4903 */
R(R_TEXTO, "de escorias de", "de escórias de", 0) /* linha 4904 */
R(R_TEXTO, "de purpura, da", "de púrpura, da", 0) /* linha 4905 */
R(R_TEXTO, "de purpura, e,", "de púrpura, e,", 0) /* linha 4906 */
R(R_TEXTO, "de rubins, mas", "de rubis, mas", 0) /* linha 4907 */
R(R_TEXTO, "do meio dia ao", "do meio-dia ao", 0) /* linha 4908 */
R(R_TEXTO, "e alaudes para", "e alaúdes para", 0) /* linha 4909 */
R(R_TEXTO, "e corôa, estai", "e coroa, estai", 0) /* linha 4910 */
R(R_TEXTO, "e dar-te-hei a", "e dar-te-ei a", 0) /* linha 4911 */
R(R_TEXTO, "em escorias, o", "em escórias, o", 0) /* linha 4912 */
R(R_TEXTO, "em purpura, em", "em púrpura, em", 0) /* linha 4913 */
R(R_TEXTO, "eu tão pouco a", "eu tampouco a", 0) /* linha 4914 */
R(R_TEXTO, "glória veem de", "glória vêm de", 0) /* linha 4915 */
R(R_TEXTO, "Ha uma geração", "Há uma geração", 0) /* linha 4916 */
R(R_TEXTO, "juízo sustem a", "juízo sustém a", 0) /* linha 4917 */
R(R_TEXTO, "meus ciumes se", "meus ciúmes se", 0) /* linha 4918 */
R(R_TEXTO, "minha suplica.", "minha súplica.", 0) /* linha 4919 */
R(R_TEXTO, "nele ha: este,", "nele há: este,", 0) /* linha 4920 */
R(R_TEXTO, "o candieiro, e", "o candeeiro, e", 0) /* linha 4921 */
R(R_TEXTO, "Porque? Porque", "Por quê? Porque", 0) /* linha 4922 */
R(R_TEXTO, "que nela ha, e", "que nela há, e", 0) /* linha 4923 */
R(R_TEXTO, "que nele ha, e", "que nele há, e", 0) /* linha 4924 */
R(R_TEXTO, "rei: Ha paz? E", "rei: Há paz? E", 0) /* linha 4925 */
R(R_TEXTO, "só benção, meu", "só bênção, meu", 0) /* linha 4926 */
R(R_TEXTO, "sua corôa; aos", "sua coroa; aos", 0) /* linha 4927 */
R(R_TEXTO, "sua suplica, e", "sua súplica, e", 0) /* linha 4928 */
R(R_TEXTO, "sua suplica, ó", "sua súplica, ó", 0) /* linha 4929 */
R(R_TEXTO, "Tão pouco Aser", "Tampouco Aser", 0) /* linha 4930 */
R(R_TEXTO, "Tão pouco para", "Tampouco para", 0) /* linha 4931 */
R(R_TEXTO, "uma benção até", "uma bênção até", 0) /* linha 4932 */
R(R_TEXTO, "uma benção, em", "uma bênção, em", 0) /* linha 4933 */
R(R_TEXTO, "vós ha, vede-o", "vós há, vede-o", 0) /* linha 4934 */
R(R_TEXTO, "a benção, ela", "a bênção, ela", 0) /* linha 4935 */
R(R_TEXTO, "a benção, que", "a bênção, que", 0) /* linha 4936 */
R(R_TEXTO, "a corôa real,", "a coroa real,", 0) /* linha 4937 */
R(R_TEXTO, "a corôa; esta", "a coroa; esta", 0) /* linha 4938 */
R(R_TEXTO, "à meia noite.", "à meia-noite.", 0) /* linha 4939 */
R(R_TEXTO, "a pratica até", "a prática até", 0) /* linha 4940 */
R(R_TEXTO, "a preza: seus", "a presa: seus", 0) /* linha 4941 */
R(R_TEXTO, "ainda retem a", "ainda retém a", 0) /* linha 4942 */
R(R_TEXTO, "As bençãos de", "As bênçãos de", 0) /* linha 4943 */
R(R_TEXTO, "com alaudes e", "com alaúdes e", 0) /* linha 4944 */
R(R_TEXTO, "de purpura, o", "de púrpura, o", 0) /* linha 4945 */
R(R_TEXTO, "de purpura. E", "de púrpura. E", 0) /* linha 4946 */
R(R_TEXTO, "diga: Ha paz?", "diga: Há paz?", 0) /* linha 4947 */
R(R_TEXTO, "Donde veem as", "Donde vêm as", 0) /* linha 4948 */
R(R_TEXTO, "e a adultera.", "e a adúltera.", 0) /* linha 4949 */
R(R_TEXTO, "e o meio dia.", "e o meio-dia.", 0) /* linha 4950 */
R(R_TEXTO, "e purpura das", "e púrpura das", 0) /* linha 4951 */
R(R_TEXTO, "Eis-aí, pois,", "Eis aí, pois,", 0) /* linha 4952 */
R(R_TEXTO, "em ciumes com", "em ciúmes com", 0) /* linha 4953 */
R(R_TEXTO, "em purpura, e", "em púrpura, e", 0) /* linha 4954 */
R(R_TEXTO, "está sobro as", "está sobre as", 0) /* linha 4955 */
R(R_TEXTO, "Ha uns homens", "Há uns homens", 0) /* linha 4956 */
R(R_TEXTO, "homem ha, que", "homem há, que", 0) /* linha 4957 */
R(R_TEXTO, "homem retem a", "homem retém a", 0) /* linha 4958 */
R(R_TEXTO, "Nada ha, fora", "Nada há, fora", 0) /* linha 4959 */
R(R_TEXTO, "nome ha, dado", "nome há, dado", 0) /* linha 4960 */
R(R_TEXTO, "para preza, e", "para presa, e", 0) /* linha 4961 */
R(R_TEXTO, "pela preza, e", "pela presa, e", 0) /* linha 4962 */
R(R_TEXTO, "Porque saí da", "Por que saí da", 0) /* linha 4963 */
R(R_TEXTO, "que lhe ás de", "que lhe hás de", 0) /* linha 4964 */
R(R_TEXTO, "quem ha, como", "quem há, como", 0) /* linha 4965 */
R(R_TEXTO, "tu ciumes por", "tu ciúmes por", 0) /* linha 4966 */
R(R_TEXTO, "tu lhes ás de", "tu lhes hás de", 0) /* linha 4967 */
R(R_TEXTO, "tu preza para", "tu presa para", 0) /* linha 4968 */
R(R_TEXTO, "uma benção do", "uma bênção do", 0) /* linha 4969 */
R(R_TEXTO, "uma benção no", "uma bênção no", 0) /* linha 4970 */
R(R_TEXTO, "a benção que", "a bênção que", 0) /* linha 4971 */
R(R_TEXTO, "a corôa real", "a coroa real", 0) /* linha 4972 */
R(R_TEXTO, "a purpura, o", "a púrpura, o", 0) /* linha 4973 */
R(R_TEXTO, "a purpura: o", "a púrpura: o", 0) /* linha 4974 */
R(R_TEXTO, "a suplica do", "a súplica do", 0) /* linha 4975 */
R(R_TEXTO, "à suplica do", "à súplica do", 0) /* linha 4976 */
R(R_TEXTO, "açoite ha, e", "açoite há, e", 0) /* linha 4977 */
R(R_TEXTO, "ao meio dia.", "ao meio-dia.", 0) /* linha 4978 */
R(R_TEXTO, "ao meio dia:", "ao meio-dia:", 0) /* linha 4979 */
R(R_TEXTO, "aqui veem os", "aqui vêm os", 0) /* linha 4980 */
R(R_TEXTO, "da Arabia, e", "da Arábia, e", 0) /* linha 4981 */
R(R_TEXTO, "da Media, os", "da Média, os", 0) /* linha 4982 */
R(R_TEXTO, "de musica de", "de música de", 0) /* linha 4983 */
R(R_TEXTO, "de musica, e", "de música, e", 0) /* linha 4984 */
R(R_TEXTO, "de purpura e", "de púrpura e", 0) /* linha 4985 */
R(R_TEXTO, "de rubins, e", "de rubis, e", 0) /* linha 4986 */
R(R_TEXTO, "do peço, que", "do poço, que", 0) /* linha 4987 */
R(R_TEXTO, "E Hamã disse", "E Hámã disse", 0) /* linha 4988 */
R(R_TEXTO, "e o outra da", "e o outro da", 0) /* linha 4989 */
R(R_TEXTO, "ele retem as", "ele retém as", 0) /* linha 4990 */
R(R_TEXTO, "em purpura e", "em púrpura e", 0) /* linha 4991 */
R(R_TEXTO, "Ha muito que", "Há muito que", 0) /* linha 4992 */
R(R_TEXTO, "muita preza.", "muita presa.", 0) /* linha 4993 */
R(R_TEXTO, "o sustem com", "o sustém com", 0) /* linha 4994 */
R(R_TEXTO, "os rubins, e", "os rubis, e", 0) /* linha 4995 */
R(R_TEXTO, "os rubins; e", "os rubis; e", 0) /* linha 4996 */
R(R_TEXTO, "para traz, é", "para trás, é", 0) /* linha 4997 */
R(R_TEXTO, "Pois que? Se", "Pois quê? Se", 0) /* linha 4998 */
R(R_TEXTO, "que te ás de", "que te hás de", 0) /* linha 4999 */
R(R_TEXTO, "Saul sairá à", "Saul saíra à", 0) /* linha 5000 */
R(R_TEXTO, "sua corôa, e", "sua coroa, e", 0) /* linha 5001 */
R(R_TEXTO, "sua preza, e", "sua presa, e", 0) /* linha 5002 */
R(R_TEXTO, "tu ás de ser", "tu hás de ser", 0) /* linha 5003 */
R(R_TEXTO, "uma corôa de", "uma coroa de", 0) /* linha 5004 */
R(R_TEXTO, "uma corôa, e", "uma coroa, e", 0) /* linha 5005 */
R(R_TEXTO, "uma pratica.", "uma prática.", 0) /* linha 5006 */
R(R_TEXTO, "vos fiéis em", "vos fieis em", 0) /* linha 5007 */
R(R_TEXTO, "a Arabia, e", "a Arábia, e", 0) /* linha 5008 */
R(R_TEXTO, "A benção do", "A bênção do", 0) /* linha 5009 */
R(R_TEXTO, "à benção do", "à bênção do", 0) /* linha 5010 */
R(R_TEXTO, "a corôa com", "a coroa com", 0) /* linha 5011 */
R(R_TEXTO, "A corôa dos", "A coroa dos", 0) /* linha 5012 */
R(R_TEXTO, "a corôa que", "a coroa que", 0) /* linha 5013 */
R(R_TEXTO, "da corôa, e", "da coroa, e", 0) /* linha 5014 */
R(R_TEXTO, "de purpura.", "de púrpura.", 0) /* linha 5015 */
R(R_TEXTO, "de rezes, e", "de reses, e", 0) /* linha 5016 */
R(R_TEXTO, "donde veem?", "donde vêm?", 0) /* linha 5017 */
R(R_TEXTO, "e purpura é", "e púrpura é", 0) /* linha 5018 */
R(R_TEXTO, "em benção a", "em bênção a", 0) /* linha 5019 */
R(R_TEXTO, "Ha caminho,", "Há caminho,", 0) /* linha 5020 */
R(R_TEXTO, "há preza; e", "há presa; e", 0) /* linha 5021 */
R(R_TEXTO, "Ha tempo de", "Há tempo de", 0) /* linha 5022 */
R(R_TEXTO, "Ha um homem", "Há um homem", 0) /* linha 5023 */
R(R_TEXTO, "nada retem.", "nada retém.", 0) /* linha 5024 */
R(R_TEXTO, "não benção.", "não bênção.", 0) /* linha 5025 */
R(R_TEXTO, "não retem a", "não retém a", 0) /* linha 5026 */
R(R_TEXTO, "ou corôa de", "ou coroa de", 0) /* linha 5027 */
R(R_TEXTO, "Pois que? O", "Pois quê? O", 0) /* linha 5028 */
R(R_TEXTO, "que retem a", "que retém a", 0) /* linha 5029 */
R(R_TEXTO, "que retem o", "que retém o", 0) /* linha 5030 */
R(R_TEXTO, "sua benção.", "sua bênção.", 0) /* linha 5031 */
R(R_TEXTO, "te corôa de", "te coroa de", 0) /* linha 5032 */
R(R_TEXTO, "tua benção.", "tua bênção.", 0) /* linha 5033 */
R(R_TEXTO, "uma benção.", "uma bênção.", 0) /* linha 5034 */
R(R_TEXTO, "a corôa da", "a coroa da", 0) /* linha 5035 */
R(R_TEXTO, "a corôa do", "a coroa do", 0) /* linha 5036 */
R(R_TEXTO, "a corôa, e", "a coroa, e", 0) /* linha 5037 */
R(R_TEXTO, "a musica e", "a música e", 0) /* linha 5038 */
R(R_TEXTO, "a preza: o", "a presa: o", 0) /* linha 5039 */
R(R_TEXTO, "a preza; e", "a presa; e", 0) /* linha 5040 */
R(R_TEXTO, "a Tadeo, e", "a Tadeu, e", 0) /* linha 5041 */
R(R_TEXTO, "da Media e", "da Média e", 0) /* linha 5042 */
R(R_TEXTO, "de musica.", "de música.", 0) /* linha 5043 */
R(R_TEXTO, "de rubins.", "de rubis.", 0) /* linha 5044 */
R(R_TEXTO, "e espia os", "e expia os", 0) /* linha 5045 */
R(R_TEXTO, "em benção.", "em bênção.", 0) /* linha 5046 */
R(R_TEXTO, "Ha caminho", "Há caminho", 0) /* linha 5047 */
R(R_TEXTO, "Ha de ser,", "Há de ser,", 0) /* linha 5048 */
R(R_TEXTO, "Ha mal que", "Há mal que", 0) /* linha 5049 */
R(R_TEXTO, "Ha, porém,", "Há, porém,", 0) /* linha 5050 */
R(R_TEXTO, "mui sabia.", "mui sábia.", 0) /* linha 5051 */
R(R_TEXTO, "Pai. Ha um", "Pai. Há um", 0) /* linha 5052 */
R(R_TEXTO, "por corôa.", "por coroa.", 0) /* linha 5053 */
R(R_TEXTO, "ser preza?", "ser presa?", 0) /* linha 5054 */
R(R_TEXTO, "sua corôa.", "sua coroa.", 0) /* linha 5055 */
R(R_TEXTO, "tua corôa.", "tua coroa.", 0) /* linha 5056 */
R(R_TEXTO, "a Eser, e", "a Aser, e", 0) /* linha 5057 */
R(R_TEXTO, "a preza e", "a presa e", 0) /* linha 5058 */
R(R_TEXTO, "Arabia, e", "Arábia, e", 0) /* linha 5059 */
R(R_TEXTO, "da Media:", "da Média:", 0) /* linha 5060 */
R(R_TEXTO, "de preza.", "de presa.", 0) /* linha 5061 */
R(R_TEXTO, "e Media e", "e Média e", 0) /* linha 5062 */
R(R_TEXTO, "e retem a", "e retém a", 0) /* linha 5063 */
R(R_TEXTO, "Ha alguns", "Há alguns", 0) /* linha 5064 */
R(R_TEXTO, "Ha um mal", "Há um mal", 0) /* linha 5065 */
R(R_TEXTO, "Ha um rio", "Há um rio", 0) /* linha 5066 */
R(R_TEXTO, "Ha um tal", "Há um tal", 0) /* linha 5067 */
R(R_TEXTO, "neles ha;", "neles há;", 0) /* linha 5068 */
R(R_TEXTO, "outro ha.", "outro há.", 0) /* linha 5069 */
R(R_TEXTO, "terra ha.", "terra há.", 0) /* linha 5070 */
R(R_TEXTO, "Ha outro", "Há outro", 0) /* linha 5071 */
R(R_TEXTO, "Ha um só", "Há um só", 0) /* linha 5072 */
R(R_TEXTO, "nela ha.", "nela há.", 0) /* linha 5073 */
R(R_TEXTO, "Ha ouro", "Há ouro", 0) /* linha 5074 */
R(R_TEXTO, "Ha, por", "Há, por", 0) /* linha 5075 */
R(R_TEXTO, "Ha só", "Há só", 0) /* linha 5076 */
R(R_INTEIRA, "Compadecer-me-hei", "Compadecer-me-ei", 0) /* linha 5077 */
R(R_INTEIRA, "considerar-te-hão", "considerar-te-ão", 0) /* linha 5078 */
R(R_INTEIRA, "incorrutibilidade", "incorruptibilidade", 0) /* linha 5079 */
R(R_INTEIRA, "restituir-vos-hei", "restituir-vos-ei", 0) /* linha 5080 */
R(R_INTEIRA, "anunciar-vos-hei", "anunciar-vos-ei", 0) /* linha 5081 */
R(R_INTEIRA, "converter-me-hei", "converter-me-ei", 0) /* linha 5082 */
R(R_INTEIRA, "perguntar-te-hei", "perguntar-te-ei", 0) /* linha 5083 */
R(R_INTEIRA, "abençoar-te-hei", "abençoar-te-ei", 0) /* linha 5084 */
R(R_INTEIRA, "abrir-se-vos-ha", "abrir-se-vos-á", 0) /* linha 5085 */
R(R_INTEIRA, "castigar-te-hei", "castigar-te-ei", 0) /* linha 5086 */
R(R_INTEIRA, "desposar-te-hei", "desposar-te-ei", 0) /* linha 5087 */
R(R_INTEIRA, "Ensinar-vos-hei", "Ensinar-vos-ei", 0) /* linha 5088 */
R(R_INTEIRA, "enviar-vô-lo-ei", "enviar-vo-lo-ei", 0) /* linha 5089 */
R(R_INTEIRA, "levantar-me-hei", "levantar-me-ei", 0) /* linha 5090 */
R(R_INTEIRA, "prantear-te-hão", "prantear-te-ão", 0) /* linha 5091 */
R(R_INTEIRA, "rejeitar-te-hei", "rejeitar-te-ei", 0) /* linha 5092 */
R(R_INTEIRA, "alegrar-me-hei", "alegrar-me-ei", 0) /* linha 5093 */
R(R_INTEIRA, "entregar-mo-lo", "entregá-lo", 0) /* linha 5094 */
R(R_INTEIRA, "exaltar-te-hei", "exaltar-te-ei", 0) /* linha 5095 */
R(R_INTEIRA, "mostrar-to-hei", "mostrar-to-ei", 0) /* linha 5096 */
R(R_INTEIRA, "queixar-me-hei", "queixar-me-ei", 0) /* linha 5097 */
R(R_INTEIRA, "ultra-passarão", "ultrapassarão", 0) /* linha 5098 */
R(R_INTEIRA, "vomitar-te-hei", "vomitar-te-ei", 0) /* linha 5099 */
R(R_INTEIRA, "aborreceram-o", "aborreceram-no", 0) /* linha 5100 */
R(R_INTEIRA, "chegar-me-hei", "chegar-me-ei", 0) /* linha 5101 */
R(R_INTEIRA, "coloquintidas", "coloquíntidas", 0) /* linha 5102 */
R(R_INTEIRA, "dar-se-vos-ha", "dar-se-vos-á", 0) /* linha 5103 */
R(R_INTEIRA, "despojaram-as", "despojaram-nas", 0) /* linha 5104 */
R(R_INTEIRA, "encontraram-o", "encontraram-no", 0) /* linha 5105 */
R(R_INTEIRA, "guiar-vos-hei", "guiar-vos-ei", 0) /* linha 5106 */
R(R_INTEIRA, "inexcrutáveis", "inescrutáveis", 0) /* linha 5107 */
R(R_INTEIRA, "Lançar-te-hão", "Lançar-te-ão", 0) /* linha 5108 */
R(R_INTEIRA, "servil-os-hão", "servi-los-ão", 0) /* linha 5109 */
R(R_INTEIRA, "sobre-maneira", "sobremaneira", 0) /* linha 5110 */
R(R_INTEIRA, "Tornar-me-hei", "Tornar-me-ei", 0) /* linha 5111 */
R(R_INTEIRA, "ajuntaram-as", "ajuntaram-nas", 0) /* linha 5112 */
R(R_INTEIRA, "alvoraçadora", "alvoroçadora", 0) /* linha 5113 */
R(R_INTEIRA, "anti-cristos", "anticristos", 0) /* linha 5114 */
R(R_INTEIRA, "dar-se-te-ha", "dar-se-te-á", 0) /* linha 5115 */
R(R_INTEIRA, "expectadores", "espectadores", 0) /* linha 5116 */
R(R_INTEIRA, "gozar-me-hei", "gozar-me-ei", 0) /* linha 5117 */
R(R_INTEIRA, "inexcrutável", "inescrutável", 0) /* linha 5118 */
R(R_INTEIRA, "louvar-te-ha", "louvar-te-á", 0) /* linha 5119 */
R(R_INTEIRA, "matar-me-hão", "matar-me-ão", 0) /* linha 5120 */
R(R_INTEIRA, "Ouvir-te-hei", "Ouvir-te-ei", 0) /* linha 5121 */
R(R_INTEIRA, "pôr-lhes-hei", "pôr-lhes-ei", 0) /* linha 5122 */
R(R_INTEIRA, "regar-te-hei", "regar-te-ei", 0) /* linha 5123 */
R(R_INTEIRA, "sepultaram-o", "sepultaram-no", 0) /* linha 5124 */
R(R_INTEIRA, "ser-lhes-hei", "ser-lhes-ei", 0) /* linha 5125 */
R(R_INTEIRA, "anti-cristo", "anticristo", 0) /* linha 5126 */
R(R_INTEIRA, "dar-lhe-hei", "dar-lhe-ei", 0) /* linha 5127 */
R(R_INTEIRA, "destilharão", "desfilharão", 0) /* linha 5128 */
R(R_INTEIRA, "far-lhe-hei", "far-lhe-ei", 0) /* linha 5129 */
R(R_INTEIRA, "Far-vos-hei", "Far-vos-ei", 0) /* linha 5130 */
R(R_INTEIRA, "interpretes", "intérpretes", 0) /* linha 5131 */
R(R_INTEIRA, "lançaram-as", "lançaram-nas", 0) /* linha 5132 */
R(R_INTEIRA, "pirhatonita", "piratonita", 0) /* linha 5133 */
R(R_INTEIRA, "ser-lhe-hei", "ser-lhe-ei", 0) /* linha 5134 */
R(R_INTEIRA, "voluntarias", "voluntárias", 0) /* linha 5135 */
R(R_INTEIRA, "adoraram-o", "adoraram-no", 0) /* linha 5136 */
R(R_INTEIRA, "amalekitas", "amalequitas", 0) /* linha 5137 */
R(R_INTEIRA, "ante-ontem", "anteontem", 0) /* linha 5138 */
R(R_INTEIRA, "corrutores", "corruptores", 0) /* linha 5139 */
R(R_INTEIRA, "Dar-te-hei", "Dar-te-ei", 0) /* linha 5140 */
R(R_INTEIRA, "distilante", "destilante", 0) /* linha 5141 */
R(R_INTEIRA, "distilarão", "destilarão", 0) /* linha 5142 */
R(R_INTEIRA, "far-te-hão", "far-te-ão", 0) /* linha 5143 */
R(R_INTEIRA, "feriram-os", "feriram-nos", 0) /* linha 5144 */
R(R_INTEIRA, "lançaram-a", "lançaram-na", 0) /* linha 5145 */
R(R_INTEIRA, "lançaram-o", "lançaram-no", 0) /* linha 5146 */
R(R_INTEIRA, "machinaram", "maquinaram", 0) /* linha 5147 */
R(R_INTEIRA, "magnificas", "magníficas", 0) /* linha 5148 */
R(R_INTEIRA, "pôr-te-hei", "pôr-te-ei", 0) /* linha 5149 */
R(R_INTEIRA, "seguiram-o", "seguiram-no", 0) /* linha 5150 */
R(R_INTEIRA, "ser-me-hão", "ser-me-ão", 0) /* linha 5151 */
R(R_INTEIRA, "servos-hão", "ser-vos-ão", 0) /* linha 5152 */
R(R_INTEIRA, "tributaria", "tributária", 0) /* linha 5153 */
R(R_INTEIRA, "vanglorias", "vanglórias", 0) /* linha 5154 */
R(R_INTEIRA, "venderam-o", "venderam-no", 0) /* linha 5155 */
R(R_INTEIRA, "amalekita", "amalequita", 0) /* linha 5156 */
R(R_INTEIRA, "archeiros", "arqueiros", 0) /* linha 5157 */
R(R_INTEIRA, "co-eleita", "coeleita", 0) /* linha 5158 */
R(R_INTEIRA, "contraria", "contrária", 0) /* linha 5159 */
R(R_INTEIRA, "deleitara", "deleitará", 0) /* linha 5160 */
R(R_INTEIRA, "exhaustos", "exaustos", 0) /* linha 5161 */
R(R_INTEIRA, "glória-se", "gloria-se", 0) /* linha 5162 */
R(R_INTEIRA, "individuo", "indivíduo", 0) /* linha 5163 */
R(R_INTEIRA, "industria", "indústria", 0) /* linha 5164 */
R(R_INTEIRA, "insignias", "insígnias", 0) /* linha 5165 */
R(R_INTEIRA, "Ir-me-hei", "Ir-me-ei", 0) /* linha 5166 */
R(R_INTEIRA, "kohatitas", "coatitas", 0) /* linha 5167 */
R(R_INTEIRA, "koratitas", "coratitas", 0) /* linha 5168 */
R(R_INTEIRA, "ladroices", "ladroíces", 0) /* linha 5169 */
R(R_INTEIRA, "magnifica", "magnífica", 0) /* linha 5170 */
R(R_INTEIRA, "pacificas", "pacíficas", 0) /* linha 5171 */
R(R_INTEIRA, "perpetuas", "perpétuas", 0) /* linha 5172 */
R(R_INTEIRA, "piramides", "pirâmides", 0) /* linha 5173 */
R(R_INTEIRA, "puseram-o", "puseram-no", 0) /* linha 5174 */
R(R_INTEIRA, "recamaras", "recâmaras", 0) /* linha 5175 */
R(R_INTEIRA, "subtileza", "sutileza", 0) /* linha 5176 */
R(R_INTEIRA, "sustem-me", "sustém-me", 0) /* linha 5177 */
R(R_INTEIRA, "tiraram-o", "tiraram-no", 0) /* linha 5178 */
R(R_INTEIRA, "tomaram-o", "tomaram-no", 0) /* linha 5179 */
R(R_INTEIRA, "Trabalhao", "Trabalhai", 0) /* linha 5180 */
R(R_INTEIRA, "zoratisas", "zoratitas", 0) /* linha 5181 */
R(R_INTEIRA, "arrateis", "arráteis", 0) /* linha 5182 */
R(R_INTEIRA, "asdotita", "asdodita", 0) /* linha 5183 */
R(R_INTEIRA, "astucias", "astúcias", 0) /* linha 5184 */
R(R_INTEIRA, "cireneos", "cireneus", 0) /* linha 5185 */
R(R_INTEIRA, "colectas", "coletas", 0) /* linha 5186 */
R(R_INTEIRA, "corrutos", "corruptos", 0) /* linha 5187 */
R(R_INTEIRA, "delicias", "delícias", 0) /* linha 5188 */
R(R_INTEIRA, "deslisar", "deslizar", 0) /* linha 5189 */
R(R_INTEIRA, "dessemos", "déssemos", 0) /* linha 5190 */
R(R_INTEIRA, "estatuas", "estátuas", 0) /* linha 5191 */
R(R_INTEIRA, "estereis", "estéreis", 0) /* linha 5192 */
R(R_INTEIRA, "excepção", "exceção", 0) /* linha 5193 */
R(R_INTEIRA, "exceptua", "excetua", 0) /* linha 5194 */
R(R_INTEIRA, "fartaras", "fartarás", 0) /* linha 5195 */
R(R_INTEIRA, "hospedes", "hóspedes", 0) /* linha 5196 */
R(R_INTEIRA, "idolatra", "idólatra", 0) /* linha 5197 */
R(R_INTEIRA, "injurias", "injúrias", 0) /* linha 5198 */
R(R_INTEIRA, "leviatan", "leviatã", 0) /* linha 5199 */
R(R_INTEIRA, "machinas", "máquinas", 0) /* linha 5200 */
R(R_INTEIRA, "Mercurio", "Mercúrio", 0) /* linha 5201 */
R(R_INTEIRA, "por-se-á", "pôr-se-á", 0) /* linha 5202 */
R(R_INTEIRA, "presagio", "presságio", 0) /* linha 5203 */
R(R_INTEIRA, "recamara", "recâmara", 0) /* linha 5204 */
R(R_INTEIRA, "servos-á", "ser-vos-á", 0) /* linha 5205 */
R(R_INTEIRA, "suplicas", "súplicas", 0) /* linha 5206 */
R(R_INTEIRA, "anekins", "enaquins", 0) /* linha 5207 */
R(R_INTEIRA, "Bençãos", "Bênçãos", 0) /* linha 5208 */
R(R_INTEIRA, "caíamos", "caiamos", 0) /* linha 5209 */
R(R_INTEIRA, "colecta", "coleta", 0) /* linha 5210 */
R(R_INTEIRA, "colonia", "colônia", 0) /* linha 5211 */
R(R_INTEIRA, "corruto", "corrupto", 0) /* linha 5212 */
R(R_INTEIRA, "cosidos", "cozidos", 0) /* linha 5213 */
R(R_INTEIRA, "dividas", "dívidas", 0) /* linha 5214 */
R(R_INTEIRA, "escoria", "escória", 0) /* linha 5215 */
R(R_INTEIRA, "espirou", "expirou", 0) /* linha 5216 */
R(R_INTEIRA, "Excepto", "Exceto", 0) /* linha 5217 */
R(R_INTEIRA, "fabulas", "fábulas", 0) /* linha 5218 */
R(R_INTEIRA, "guizado", "guisado", 0) /* linha 5219 */
R(R_INTEIRA, "laminas", "lâminas", 0) /* linha 5220 */
R(R_INTEIRA, "licitas", "lícitas", 0) /* linha 5221 */
R(R_INTEIRA, "lubrica", "lúbrica", 0) /* linha 5222 */
R(R_INTEIRA, "maculas", "máculas", 0) /* linha 5223 */
R(R_INTEIRA, "magicas", "mágicas", 0) /* linha 5224 */
R(R_INTEIRA, "olfacto", "olfato", 0) /* linha 5225 */
R(R_INTEIRA, "peco-te", "peço-te", 0) /* linha 5226 */
R(R_INTEIRA, "publica", "pública", 0) /* linha 5227 */
R(R_INTEIRA, "Saíamos", "Saiamos", 0) /* linha 5228 */
R(R_INTEIRA, "saíamos", "saiamos", 0) /* linha 5229 */
R(R_INTEIRA, "sais-te", "saíste", 0) /* linha 5230 */
R(R_INTEIRA, "secundo", "segundo", 0) /* linha 5231 */
R(R_INTEIRA, "sosterá", "susterá", 0) /* linha 5232 */
R(R_INTEIRA, "tesoiro", "tesouro", 0) /* linha 5233 */
R(R_INTEIRA, "ulceras", "úlceras", 0) /* linha 5234 */
R(R_INTEIRA, "viram-o", "viram-no", 0) /* linha 5235 */
R(R_INTEIRA, "abstêm", "abstém", 0) /* linha 5236 */
R(R_INTEIRA, "asimos", "ázimos", 0) /* linha 5237 */
R(R_INTEIRA, "cassia", "cássia", 0) /* linha 5238 */
R(R_INTEIRA, "corôas", "coroas", 0) /* linha 5239 */
R(R_INTEIRA, "cosida", "cozida", 0) /* linha 5240 */
R(R_INTEIRA, "dizima", "dízima", 0) /* linha 5241 */
R(R_INTEIRA, "guizar", "guisar", 0) /* linha 5242 */
R(R_INTEIRA, "halito", "hálito", 0) /* linha 5243 */
R(R_INTEIRA, "impias", "ímpias", 0) /* linha 5244 */
R(R_INTEIRA, "intima", "íntima", 0) /* linha 5245 */
R(R_INTEIRA, "Johnan", "Johanan", 0) /* linha 5246 */
R(R_INTEIRA, "kineos", "queneus", 0) /* linha 5247 */
R(R_INTEIRA, "Lazaro", "Lázaro", 0) /* linha 5248 */
R(R_INTEIRA, "magica", "mágica", 0) /* linha 5249 */
R(R_INTEIRA, "nodoas", "nódoas", 0) /* linha 5250 */
R(R_INTEIRA, "propôr", "propor", 0) /* linha 5251 */
R(R_INTEIRA, "sereia", "sereis", 0) /* linha 5252 */
R(R_INTEIRA, "tisica", "tísica", 0) /* linha 5253 */
R(R_INTEIRA, "argue", "argui", 0) /* linha 5254 */
R(R_INTEIRA, "Corôa", "Coroa", 0) /* linha 5255 */
R(R_INTEIRA, "cousa", "coisa", 0) /* linha 5256 */
R(R_INTEIRA, "emfim", "enfim", 0) /* linha 5257 */
R(R_INTEIRA, "Fieis", "Fiéis", 0) /* linha 5258 */
R(R_INTEIRA, "impia", "ímpia", 0) /* linha 5259 */
R(R_INTEIRA, "impôr", "impor", 0) /* linha 5260 */
R(R_INTEIRA, "locar", "lugar", 0) /* linha 5261 */
R(R_INTEIRA, "Logar", "Lugar", 0) /* linha 5262 */
R(R_INTEIRA, "o[o?]", "o", 0) /* linha 5263 */
R(R_INTEIRA, "Orion", "Órion", 0) /* linha 5264 */
R(R_INTEIRA, "orion", "Órion", 0) /* linha 5265 */
R(R_INTEIRA, "pul-a", "pu-la", 0) /* linha 5266 */
R(R_INTEIRA, "regoa", "régua", 0) /* linha 5267 */
R(R_INTEIRA, "Retem", "Retém", 0) /* linha 5268 */
R(R_INTEIRA, "sesta", "sexta", 0) /* linha 5269 */
R(R_INTEIRA, "Vô-lo", "Vo-lo", 0) /* linha 5270 */
R(R_INTEIRA, "opôr", "opor", 0) /* linha 5271 */
R(R_INTEIRA, "crú", "cru", 0) /* linha 5272 */
R(R_INTEIRA, "Más", "Mas", 0) /* linha 5273 */
R(R_INTEIRA, "poz", "pôs", 0) /* linha 5274 */
/* Mesóclise -hei/-hão depois de pronome (louvar-te-hei -> louvar-te-ei, Ser-vos-hão -> Ser-vos-ão).
       Fica depois da parte 12 para não mudar o texto que as frases da revisão procuram. */
R(R_TEXTO, "-me-hei", "-me-ei", 0) /* linha 5292 */
R(R_TEXTO, "-me-hão", "-me-ão", 0) /* linha 5292 */
R(R_TEXTO, "-te-hei", "-te-ei", 0) /* linha 5292 */
R(R_TEXTO, "-te-hão", "-te-ão", 0) /* linha 5292 */
R(R_TEXTO, "-se-hei", "-se-ei", 0) /* linha 5292 */
R(R_TEXTO, "-se-hão", "-se-ão", 0) /* linha 5292 */
R(R_TEXTO, "-nos-hei", "-nos-ei", 0) /* linha 5292 */
R(R_TEXTO, "-nos-hão", "-nos-ão", 0) /* linha 5292 */
R(R_TEXTO, "-vos-hei", "-vos-ei", 0) /* linha 5292 */
R(R_TEXTO, "-vos-hão", "-vos-ão", 0) /* linha 5292 */
R(R_TEXTO, "-lhe-hei", "-lhe-ei", 0) /* linha 5292 */
R(R_TEXTO, "-lhe-hão", "-lhe-ão", 0) /* linha 5292 */
R(R_TEXTO, "-lhes-hei", "-lhes-ei", 0) /* linha 5292 */
R(R_TEXTO, "-lhes-hão", "-lhes-ão", 0) /* linha 5292 */
R(R_GERUNDIO, "", "", 0) /* linha 5295 */
#endif
