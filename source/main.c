#include "Intellisense.h"
#include "gba_macros.h"
#include <gba_types.h>
#include "gba_gfx.h"
#include "gba_drawing.h"
#include "gba_mathUtil.h"
#include <gba_input.h>
#include <maxmod.h>
#include <gba.h>
#include <gba_sound.h>

#include <stdio.h>

#include <string.h>

#include "soundbank.h"
#include "soundbank_bin.h"

#include "image_bin.h"

typedef unsigned char byte;

//const long szs[3286L] = {76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 110, 988, 2182, 752, 498, 460, 466, 352, 340, 602, 942, 906, 822, 906, 1058, 1248, 1100, 822, 1508, 1694, 1654, 1536, 1578, 1682, 1414, 1038, 1178, 1150, 1088, 1014, 720, 1364, 1394, 1428, 1304, 1116, 946, 950, 980, 814, 794, 834, 854, 1044, 1270, 1452, 1512, 1444, 1392, 1284, 1158, 780, 794, 826, 864, 860, 964, 1248, 1322, 1378, 1306, 1290, 1224, 1156, 946, 964, 1040, 1054, 1162, 1148, 1326, 1420, 1366, 1372, 1304, 1250, 960, 814, 866, 1062, 1460, 1500, 1608, 1542, 1754, 1602, 1616, 1832, 1796, 1882, 1488, 1344, 1344, 1338, 1372, 1298, 1312, 1254, 1196, 1100, 1096, 1100, 1152, 1164, 1150, 1186, 1212, 1212, 1210, 1288, 1210, 1240, 1216, 1158, 1194, 1224, 1242, 1228, 1240, 1230, 1268, 1302, 1360, 1390, 1362, 1460, 1286, 1302, 1342, 1376, 1392, 1406, 1400, 1446, 1452, 1484, 1352, 1272, 1292, 1312, 1514, 1552, 1980, 2442, 2650, 2346, 1624, 1564, 1880, 2038, 1882, 1692, 1088, 392, 1426, 6336, 7320, 1414, 4280, 4876, 76, 76, 76, 76, 76, 76, 76, 76, 76, 94, 440, 680, 748, 796, 636, 680, 528, 396, 88, 78, 76, 76, 76, 76, 76, 76, 80, 76, 76, 76, 76, 76, 94, 144, 146, 186, 116, 100, 188, 1226, 190, 190, 190, 190, 190, 190, 190, 76, 288, 88, 1974, 3306, 3536, 2638, 1134, 396, 842, 2042, 2800, 3232, 2344, 2084, 1612, 1092, 788, 684, 504, 496, 450, 466, 474, 482, 438, 554, 1052, 1336, 1578, 1666, 1570, 1750, 2364, 2798, 4114, 4442, 3490, 2290, 1576, 992, 432, 276, 260, 226, 190, 190, 232, 248, 274, 256, 260, 258, 270, 266, 256, 296, 260, 276, 280, 262, 286, 296, 284, 302, 318, 292, 304, 304, 330, 304, 290, 328, 300, 318, 278, 278, 262, 280, 284, 282, 292, 302, 310, 280, 318, 322, 278, 310, 314, 416, 472, 710, 808, 868, 706, 532, 424, 408, 466, 1500, 1592, 1690, 1244, 1256, 1326, 1298, 1304, 1326, 1204, 1310, 1296, 1312, 1312, 1328, 1300, 1308, 1386, 1308, 1250, 1298, 1334, 1300, 1310, 1290, 1294, 1404, 1396, 1414, 1410, 1418, 1414, 1372, 1370, 1352, 1306, 1378, 1378, 1410, 1438, 1412, 1376, 1430, 1474, 1954, 2458, 2520, 1586, 878, 984, 1572, 1544, 1144, 1126, 1692, 240, 76, 76, 76, 76, 84, 150, 214, 246, 268, 244, 320, 648, 966, 866, 716, 422, 86, 80, 80, 80, 80, 80, 80, 80, 5838, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 868, 1890, 1318, 80, 78, 94, 78, 88, 188, 476, 786, 916, 1026, 1046, 1144, 1052, 1054, 932, 848, 892, 744, 686, 756, 732, 668, 622, 610, 650, 678, 708, 668, 600, 666, 666, 656, 604, 632, 584, 560, 602, 568, 606, 612, 612, 608, 636, 644, 656, 628, 622, 590, 600, 608, 560, 590, 596, 590, 712, 858, 976, 1210, 1498, 1560, 980, 840, 708, 664, 702, 804, 928, 1164, 1676, 1884, 1862, 1856, 1468, 1052, 918, 906, 866, 920, 1008, 950, 878, 1134, 1124, 1018, 1138, 1168, 770, 764, 878, 844, 800, 750, 684, 742, 908, 970, 856, 716, 776, 794, 940, 1188, 1550, 1864, 1878, 1668, 872, 826, 872, 1150, 862, 1164, 1076, 1082, 1028, 976, 1236, 1438, 1228, 1268, 1212, 1002, 1002, 780, 1552, 1556, 1608, 1614, 1572, 1448, 1188, 1104, 1146, 1318, 1580, 1814, 1644, 1550, 1422, 1424, 1458, 1612, 1386, 1152, 1018, 868, 894, 1018, 1078, 956, 908, 926, 866, 874, 870, 872, 984, 1404, 1514, 1478, 1494, 1552, 1570, 1510, 1466, 1500, 1358, 1416, 1612, 1512, 1422, 1252, 1260, 1148, 1184, 1206, 1230, 1224, 1212, 1180, 1174, 1202, 1218, 984, 940, 1000, 1320, 940, 770, 958, 1264, 1218, 590, 80, 80, 80, 76, 76, 76, 76, 76, 76, 80, 78, 80, 544, 1612, 1660, 2046, 2444, 2684, 2870, 2842, 2964, 3120, 3272, 3446, 3496, 3526, 3440, 3858, 5666, 4156, 1626, 742, 242, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 92, 78, 78, 78, 78, 340, 96, 78, 78, 78, 526, 430, 78, 76, 574, 946, 142, 386, 1050, 2554, 2222, 1768, 1570, 1456, 1354, 1088, 922, 852, 934, 950, 922, 814, 812, 876, 868, 976, 930, 870, 766, 704, 664, 624, 656, 690, 762, 884, 1016, 1018, 964, 648, 626, 730, 712, 788, 994, 1064, 946, 1070, 1024, 1056, 1098, 1200, 1248, 1164, 1080, 984, 1048, 1054, 1106, 1114, 1136, 1274, 1718, 1682, 1780, 78, 78, 78, 78, 78, 78, 76, 76, 76, 76, 76, 76, 76, 396, 2456, 4024, 5274, 5984, 6324, 5462, 4970, 3830, 3550, 3466, 3384, 2894, 2656, 2672, 2556, 2584, 2530, 2528, 2498, 2374, 2210, 2110, 2044, 1876, 1948, 1996, 1984, 1900, 1858, 1788, 1784, 1818, 1992, 2120, 2198, 2050, 1842, 2806, 2246, 1444, 740, 640, 618, 1046, 1320, 1792, 2458, 2098, 1672, 1840, 2110, 2058, 1904, 1884, 1886, 1844, 1864, 1992, 2126, 2562, 2568, 2304, 2510, 2492, 2474, 2540, 2588, 2708, 2726, 2864, 2824, 2922, 2878, 2798, 2806, 2890, 2992, 3038, 3050, 3074, 3134, 3140, 3120, 3176, 3260, 3218, 3306, 3260, 3528, 3732, 3348, 3586, 3740, 3858, 3922, 3986, 4224, 4086, 3606, 3210, 2988, 3074, 3038, 2838, 2664, 2558, 2400, 2244, 2084, 1982, 1870, 1786, 1642, 1454, 1062, 748, 626, 424, 326, 144, 80, 80, 78, 138, 574, 810, 1194, 1900, 2098, 2370, 2862, 2912, 2926, 2446, 2264, 1988, 1836, 1866, 1754, 1844, 1774, 1846, 1834, 1812, 2246, 2096, 1760, 1562, 1586, 1574, 1478, 1470, 1490, 1470, 1528, 1378, 3200, 3568, 3292, 3386, 3090, 3284, 4094, 6234, 2154, 1470, 1716, 2294, 1676, 1654, 1632, 1888, 2386, 3016, 3264, 3334, 3594, 3772, 3764, 3666, 3704, 3702, 3296, 3612, 3698, 3702, 2230, 2212, 4772, 2014, 3596, 3144, 3198, 3832, 4304, 4316, 3796, 3450, 3160, 2726, 2700, 2068, 862, 882, 1758, 998, 1018, 1056, 1024, 942, 832, 866, 1020, 968, 1034, 1032, 828, 844, 900, 868, 862, 888, 874, 830, 842, 874, 998, 918, 1082, 936, 1626, 1506, 1640, 1768, 1798, 1208, 902, 876, 1056, 1048, 1496, 1682, 1520, 1356, 1022, 968, 938, 1008, 1270, 1368, 1236, 986, 1028, 1040, 1144, 1432, 1510, 980, 986, 974, 994, 1282, 1334, 1290, 1028, 1020, 1226, 1384, 1602, 1410, 918, 842, 994, 954, 1264, 1346, 1056, 1012, 1020, 1010, 1006, 1370, 1510, 1054, 976, 904, 754, 994, 1552, 1116, 1112, 1104, 1066, 902, 638, 696, 782, 934, 1140, 1216, 1160, 1074, 896, 692, 194, 80, 80, 80, 80, 80, 80, 80, 80, 206, 268, 254, 174, 88, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 150, 182, 238, 228, 250, 164, 106, 80, 80, 80, 84, 96, 112, 144, 206, 330, 430, 430, 520, 636, 780, 974, 1064, 1244, 1322, 1346, 1216, 1234, 1152, 1168, 1008, 892, 896, 594, 356, 210, 78, 690, 1288, 1658, 2278, 2534, 2378, 2668, 2022, 1746, 1578, 1588, 1574, 1614, 1596, 1548, 1516, 1466, 1454, 1468, 1432, 1456, 1426, 1450, 1438, 1514, 1484, 1462, 1494, 1456, 1540, 1606, 1668, 1764, 1890, 1890, 1890, 1798, 1790, 1630, 1564, 1556, 1480, 1100, 566, 608, 600, 582, 600, 584, 604, 712, 740, 868, 852, 546, 444, 160, 160, 346, 794, 1420, 1532, 1478, 1510, 1594, 1426, 1258, 1180, 1170, 1148, 1152, 1184, 1174, 1186, 1166, 1162, 1184, 1136, 1118, 1098, 1086, 1094, 1072, 1078, 1050, 1082, 1056, 1022, 1138, 1154, 1230, 1332, 1308, 1460, 1554, 1612, 1586, 1526, 1368, 1162, 1418, 1560, 1540, 1528, 1436, 1524, 1512, 1404, 1658, 1660, 1616, 1598, 1558, 1524, 1496, 1520, 1866, 1826, 1974, 2282, 2718, 2538, 2052, 1592, 1516, 1770, 1696, 1534, 1632, 1918, 2072, 2260, 2262, 2296, 1364, 602, 76, 76, 76, 76, 76, 76, 76, 466, 952, 1322, 1332, 1410, 1402, 1468, 1376, 1368, 1290, 648, 646, 632, 660, 662, 638, 640, 686, 710, 822, 1126, 1276, 1308, 1296, 1362, 1234, 1132, 1082, 832, 634, 642, 652, 630, 654, 640, 670, 656, 674, 646, 658, 680, 666, 692, 700, 688, 662, 644, 628, 632, 646, 652, 688, 648, 620, 852, 948, 1104, 1222, 1100, 1228, 1176, 1120, 1094, 1100, 1014, 1018, 932, 726, 728, 724, 692, 762, 856, 782, 774, 778, 738, 702, 690, 670, 726, 742, 796, 774, 766, 682, 690, 704, 714, 726, 752, 726, 818, 982, 1210, 1132, 1310, 916, 750, 828, 1078, 1552, 2458, 4786, 8476, 8246, 7348, 6634, 4900, 2142, 1528, 892, 108, 76, 76, 76, 76, 76, 76, 76, 76, 292, 144, 108, 94, 76, 1944, 3878, 4844, 5202, 5260, 4496, 4188, 4700, 4976, 4954, 4462, 4198, 4100, 4244, 4288, 4192, 3924, 3620, 3692, 3470, 3278, 5064, 5746, 7108, 8994, 9040, 8552, 7936, 5006, 2696, 2642, 2774, 2554, 2540, 2536, 2586, 2606, 2546, 2238, 1890, 1506, 1670, 2184, 2082, 2084, 2952, 3920, 4452, 3044, 2706, 2276, 1742, 1734, 1938, 2130, 2152, 1944, 2098, 2468, 2520, 2328, 2564, 2750, 2364, 2320, 2446, 2492, 2562, 2640, 2994, 4638, 4964, 5210, 4810, 4416, 3674, 2680, 1856, 1824, 2182, 3110, 4950, 5520, 5384, 5890, 5724, 5354, 5318, 5490, 6324, 8390, 10856, 11028, 10078, 6852, 3950, 2804, 2064, 1558, 1320, 1296, 1356, 1368, 1438, 1580, 1664, 1698, 1652, 1566, 1586, 1590, 1558, 1590, 1600, 1574, 1636, 1628, 1552, 1568, 1572, 1524, 1572, 1478, 1498, 1512, 1524, 1584, 1530, 1592, 1576, 1514, 1486, 1506, 1560, 1536, 1526, 1580, 1606, 1610, 1622, 1662, 1646, 1714, 1676, 1684, 1664, 1650, 1610, 1646, 1622, 1642, 1596, 1636, 1646, 1648, 1656, 1598, 1546, 1574, 1524, 1576, 1542, 1562, 1566, 1586, 1566, 1544, 1502, 1556, 1584, 1566, 1658, 1770, 1760, 1734, 1606, 1492, 1632, 1730, 1826, 1280, 1310, 1230, 1386, 1518, 1658, 1974, 2058, 1774, 2512, 2460, 2934, 2598, 2612, 2522, 2492, 2610, 2180, 1888, 1784, 1610, 1658, 1616, 1616, 1572, 1518, 1526, 1524, 1492, 1500, 1528, 1524, 1508, 1476, 1458, 1470, 1472, 1468, 1462, 1422, 1504, 1506, 1362, 1338, 1428, 1402, 1240, 1108, 1008, 1004, 1032, 894, 890, 900, 974, 930, 882, 896, 900, 902, 866, 916, 896, 1106, 1960, 3048, 3328, 3792, 3328, 3654, 2492, 1742, 1582, 1578, 1760, 2328, 2694, 2744, 2088, 2280, 2458, 2450, 2780, 2986, 3450, 4056, 4094, 4778, 8336, 10784, 8092, 4672, 1410, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 1224, 2740, 2990, 2882, 3182, 4406, 3716, 3892, 3906, 3880, 3712, 3520, 3594, 3624, 3750, 3786, 3836, 3438, 3448, 3440, 3472, 3282, 3340, 3576, 3918, 4270, 5028, 5328, 5412, 5326, 5364, 5876, 6078, 5888, 5782, 5818, 5814, 5394, 5040, 5036, 4902, 4528, 4466, 4098, 4082, 3872, 3784, 3646, 3672, 3722, 3564, 3408, 3792, 4218, 4526, 4644, 4430, 4410, 4002, 3978, 2358, 2040, 1500, 868, 812, 864, 736, 702, 652, 766, 814, 878, 854, 816, 840, 1160, 1180, 1290, 1372, 1874, 1966, 1990, 1896, 2034, 1740, 994, 1004, 1252, 1430, 1418, 1330, 1376, 1620, 1420, 1510, 1748, 1658, 1890, 2080, 2156, 2322, 2866, 2862, 2576, 2686, 1998, 1534, 1418, 1374, 1586, 1836, 2330, 2588, 2656, 2440, 1882, 1306, 858, 1274, 1324, 2372, 1324, 1166, 1262, 1196, 1044, 1016, 1116, 1144, 1150, 1600, 2320, 554, 1240, 2144, 4144, 1932, 1526, 1426, 1490, 1392, 1766, 1382, 2688, 2372, 528, 726, 2248, 4348, 1106, 1450, 4026, 1626, 830, 1690, 2036, 1418, 2834, 1102, 1034, 1446, 1196, 798, 728, 664, 668, 672, 730, 1078, 1218, 684, 700, 902, 854, 742, 810, 750, 1544, 1250, 942, 994, 1554, 1768, 1636, 1288, 1314, 1288, 1362, 1450, 1412, 1376, 1436, 1346, 1318, 1430, 2734, 2036, 1340, 1010, 78, 596, 228, 146, 286, 494, 772, 1074, 1282, 1006, 1790, 2060, 1772, 1656, 1514, 1442, 1482, 1938, 2816, 3730, 3910, 4226, 4634, 4766, 4096, 3532, 3014, 2790, 2396, 2550, 3486, 3458, 3060, 4014, 4970, 5894, 6412, 6414, 4936, 4144, 2938, 3264, 4530, 3508, 2406, 2546, 3012, 3032, 2114, 946, 716, 834, 1084, 1344, 1652, 1900, 1892, 1790, 1662, 1518, 1448, 1322, 1306, 1574, 1480, 1416, 1438, 1424, 1488, 1328, 1378, 1348, 1316, 1154, 1122, 1064, 992, 1008, 994, 996, 760, 678, 664, 630, 590, 728, 966, 974, 986, 1038, 1128, 1462, 1558, 2452, 2444, 2378, 2436, 2304, 2156, 2072, 1870, 1920, 1798, 1492, 1362, 1314, 1382, 1484, 1600, 1640, 1350, 1898, 1384, 1412, 1420, 1880, 1502, 1564, 1370, 916, 918, 986, 2838, 3454, 1242, 612, 522, 632, 662, 824, 898, 1006, 1274, 1384, 1100, 784, 584, 612, 634, 612, 572, 576, 580, 808, 1010, 1204, 930, 568, 576, 594, 726, 998, 1312, 1348, 1090, 784, 534, 552, 566, 762, 2032, 1694, 1464, 1570, 1472, 1386, 1312, 1314, 1250, 1332, 1314, 1298, 1316, 1294, 1326, 1338, 1316, 1370, 1868, 1804, 1582, 1438, 1414, 1438, 1444, 1396, 1370, 1372, 1390, 1384, 1368, 1378, 1368, 1348, 1354, 1356, 1330, 1426, 1948, 2274, 2376, 2398, 2290, 2058, 1576, 1488, 1484, 1476, 1452, 1462, 1458, 1480, 1422, 1784, 2796, 3066, 9578, 7278, 104, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 256, 286, 232, 98, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 194, 960, 1444, 1680, 1496, 1050, 1310, 1800, 2448, 4658, 1958, 1340, 976, 872, 846, 846, 788, 738, 776, 710, 874, 1028, 1124, 1122, 1066, 1310, 1502, 1606, 1702, 1634, 1706, 1680, 1684, 1628, 1622, 1628, 1534, 1570, 1544, 1514, 1466, 1470, 1490, 1478, 1482, 1570, 1548, 1572, 1556, 1538, 1544, 1690, 1720, 888, 848, 874, 868, 884, 830, 976, 1020, 1208, 1084, 976, 904, 952, 1032, 1116, 1240, 1216, 982, 1024, 1122, 1190, 1210, 1280, 1728, 2284, 2280, 2456, 2602, 2034, 1164, 852, 922, 980, 890, 2756, 334, 330, 360, 340, 360, 320, 316, 330, 368, 620, 1150, 1984, 2070, 1628, 1254, 1204, 1238, 1260, 1238, 1262, 1242, 1250, 1244, 1276, 1248, 1258, 1246, 1196, 1228, 1388, 1388, 1498, 2488, 2026, 2070, 1952, 2166, 2446, 2644, 2722, 1998, 1744, 1778, 1402, 1036, 1038, 1112, 1410, 1598, 1952, 2296, 1686, 1510, 920, 860, 880, 970, 1316, 1334, 1486, 1498, 1512, 1808, 1866, 1242, 1594, 1436, 1452, 1854, 1630, 1562, 1702, 2166, 5804, 6066, 76, 76, 2628, 6548, 4230, 1390, 1350, 1388, 1368, 1486, 1490, 6482, 5856, 76, 76, 2700, 7548, 5876, 1308, 1292, 1296, 1250, 1212, 1154, 1390, 4718, 4104, 2176, 1292, 1030, 2840, 2396, 1084, 1080, 1084, 1066, 1060, 1066, 958, 890, 900, 838, 828, 928, 988, 1158, 1466, 2124, 2680, 3284, 3008, 2682, 2492, 2840, 2566, 2344, 3058, 2992, 3118, 2994, 2816, 2674, 2422, 2424, 2408, 2350, 2294, 2354, 2190, 2056, 1938, 1946, 1966, 1928, 1940, 1942, 1924, 1976, 1928, 1956, 1952, 1944, 1896, 1858, 1884, 1846, 1868, 1916, 1928, 1932, 1904, 1982, 2058, 2084, 2066, 2178, 2240, 2410, 2658, 2900, 3180, 3394, 3020, 2418, 1170, 932, 1176, 1600, 2480, 2410, 1194, 1086, 1282, 1852, 1610, 424, 80, 76, 76, 76, 766, 978, 1032, 1340, 1988, 1056, 838, 1140, 1104, 980, 992, 692, 592, 834, 544, 326, 1566, 1092, 858, 810, 1282, 1592, 1842, 1998, 2270, 3148, 3524, 3544, 3462, 2250, 2870, 2980, 3176, 3074, 2538, 2410, 2308, 2726, 2716, 2480, 2316, 2236, 2202, 2268, 2260, 2260, 2278, 2222, 2282, 2316, 2302, 2214, 2206, 2208, 2158, 2106, 2090, 2066, 2090, 2098, 2086, 2116, 2126, 2072, 2094, 2034, 1976, 2006, 2050, 2028, 2028, 2048, 1986, 1994, 1920, 1876, 1984, 1996, 1926, 1872, 1764, 1832, 1854, 2108, 2032, 1404, 1606, 1712, 1606, 1476, 1566, 1670, 1750, 1592, 1514, 1596, 1588, 1758, 1812, 1846, 1952, 2150, 2274, 2054, 1868, 1822, 1930, 2252, 1698, 1030, 1152, 1326, 1096, 1468, 2114, 1208, 1882, 76, 80, 80, 80, 80, 80, 80, 84, 172, 280, 326, 356, 382, 430, 462, 556, 572, 574, 624, 778, 838, 904, 960, 1066, 1098, 1162, 1228, 1360, 1514, 1634, 1752, 1442, 1108, 900, 736, 654, 698, 732, 732, 750, 768, 818, 832, 870, 924, 948, 976, 1018, 1072, 1134, 1154, 1226, 1304, 1398, 1430, 1522, 1606, 1452, 1418, 1334, 1264, 1202, 1190, 1394, 1372, 1484, 1560, 1674, 1654, 1730, 1732, 1784, 1954, 1940, 2044, 1982, 1980, 1576, 1312, 1202, 954, 924, 960, 966, 1040, 1952, 766, 76, 76, 76, 106, 348, 754, 1370, 1138, 1664, 2060, 2256, 2342, 2306, 2390, 2200, 2214, 2472, 2346, 2518, 2420, 2152, 2222, 2368, 2228, 2024, 2148, 2100, 2108, 2246, 1970, 2388, 2742, 2546, 2004, 2148, 1886, 1734, 1512, 1146, 1296, 1090, 1058, 1108, 1014, 1146, 1152, 1078, 2218, 1176, 902, 1036, 2074, 2438, 908, 462, 504, 414, 568, 550, 2106, 76, 76, 76, 2148, 76, 76, 76, 76, 396, 4186, 1524, 76, 416, 1152, 76, 76, 88, 196, 380, 390, 230, 140, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 248, 1112, 1384, 1030, 1056, 1194, 1246, 816, 526, 414, 398, 364, 480, 682, 916, 1162, 1584, 1974, 1944, 1748, 1642, 1922, 1688, 1350, 1028, 718, 730, 698, 1314, 1954, 2302, 3498, 1904, 1856, 1820, 2168, 2406, 2506, 1754, 1990, 2118, 2364, 2472, 2458, 2446, 2370, 2226, 1596, 1250, 1104, 1206, 1314, 1522, 1490, 1414, 1204, 1382, 1594, 1886, 1888, 1764, 1742, 1692, 1544, 1274, 1392, 1616, 1638, 1348, 1570, 1302, 1342, 1212, 1452, 1630, 1512, 1386, 1382, 1274, 1120, 1194, 1298, 1182, 982, 908, 948, 1008, 936, 862, 1446, 1500, 1602, 1570, 1658, 1804, 1424, 1090, 992, 1064, 1086, 1140, 1140, 988, 1012, 1064, 1202, 1248, 1158, 1224, 1142, 1132, 1226, 1636, 2106, 1946, 1458, 1324, 1236, 778, 646, 232, 382, 528, 220, 300, 168, 132, 222, 552, 868, 1486, 1600, 2792, 3586, 3342, 2918, 2228, 2348, 2408, 2162, 1426, 818, 972, 952, 890, 596, 644, 924, 1122, 1724, 2062, 2302, 2626, 2462, 2272, 2056, 2024, 1820, 1806, 1746, 1604, 1778, 1766, 1776, 1826, 1804, 1850, 1878, 1834, 1806, 1820, 1754, 1792, 1824, 1808, 1946, 2074, 1800, 1736, 1692, 1724, 1810, 1808, 1800, 1878, 1868, 1950, 1890, 1952, 1918, 1904, 1902, 1912, 1914, 1888, 1878, 1952, 1940, 1902, 1852, 1800, 1746, 1742, 1726, 1720, 1734, 1684, 1746, 1708, 1642, 1340, 1352, 1290, 1094, 956, 1026, 1048, 982, 970, 718, 730, 784, 746, 736, 800, 872, 948, 790, 902, 1036, 964, 844, 552, 306, 84, 76, 76, 76, 76, 76, 76, 76, 76, 80, 184, 88, 242, 248, 138, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 80, 560, 1024, 2138, 3816, 5506, 5764, 6538, 3158, 4344, 4914, 5306, 5954, 5378, 5062, 3400, 3718, 4116, 4702, 4530, 3890, 2524, 1788, 2160, 2680, 3474, 3786, 2882, 860, 752, 792, 722, 698, 678, 704, 676, 680, 700, 732, 764, 768, 780, 790, 752, 774, 756, 740, 764, 776, 826, 834, 860, 900, 914, 952, 972, 994, 1078, 1190, 1280, 1406, 1540, 1574, 1668, 1626, 1650, 1786, 1800, 1882, 1872, 1892, 1896, 1608, 1500, 1474, 1180, 778, 844, 1122, 1124, 1224, 1588, 1336, 690, 732, 1936, 3210, 3582, 2748, 1100, 468, 498, 650, 810, 810, 486, 490, 722, 708, 576, 742, 722, 76, 76, 76, 76, 172, 384, 668, 896, 1058, 840, 1194, 810, 660, 654, 352, 240, 320, 606, 706, 794, 880, 736, 838, 1786, 1790, 1790, 1618, 1512, 1410, 1360, 1396, 1308, 1304, 1302, 1380, 1292, 1254, 1198, 1208, 1292, 1244, 1236, 1214, 1218, 1246, 1200, 1280, 1200, 1246, 1198, 1212, 1152, 1150, 1198, 1176, 1200, 1120, 1042, 956, 964, 1194, 1480, 1392, 1154, 1040, 1008, 1140, 1276, 1368, 1592, 1416, 1510, 1550, 2246, 1748, 1518, 1646, 1776, 1770, 1910, 1534, 1826, 2416, 2846, 3384, 3232, 2760, 2100, 1260, 1926, 3378, 3244, 3606, 3476, 3344, 2240, 1476, 3362, 2978, 3776, 3876, 3550, 1656, 2346, 3886, 3170, 3832, 3940, 2784, 1122, 3496, 2414, 3336, 3748, 3342, 1026, 2354, 2702, 2532, 3306, 3342, 3084, 2232, 1126, 1506, 2120, 1864, 1300, 814, 564, 604, 550, 206, 576, 944, 826, 404, 408, 682, 336, 324, 480, 404, 484, 564, 562, 480, 560, 492, 436, 572, 888, 1078, 1046, 742, 686, 418, 640, 1120, 1154, 1208, 1172, 1140, 1020, 1218, 3594, 368, 370, 634, 632, 1082, 1424, 1420, 1760, 1726, 1604, 1544, 1496, 1372, 1222, 1036, 918, 758, 788, 670, 916, 2582, 3184, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76};

u8 myMixingBuffer[ MM_MIXLEN_16KHZ ] __attribute((aligned(4)));

/*long siz(long idx){
	if(idx <= 0) return 0;
	
	static long a = 0;
	
	a += szs[idx - 1];
	
	return a;
}*/

void maxmodInit( void )
{
    irqInit();
    irqSet( IRQ_VBLANK, mmVBlank );
    irqEnable( IRQ_VBLANK );

    u8* myData;
    mm_gba_system mySystem;

    // allocate data for channel buffers & wave buffer (malloc'd data goes to EWRAM)
    // Use the SIZEOF definitions to calculate how many bytes to reserve
    myData = (u8*)malloc( 8 * (MM_SIZEOF_MODCH
                               +MM_SIZEOF_ACTCH
                               +MM_SIZEOF_MIXCH)
                          +MM_MIXLEN_16KHZ );

    // setup system info
    // 16KHz software mixing rate, select from mm_mixmode
    mySystem.mixing_mode       = MM_MIX_16KHZ;

    // number of module/mixing channels
    // higher numbers offer better polyphony at the expense
    // of more memory and/or CPU usage.
    mySystem.mod_channel_count = 8;
    mySystem.mix_channel_count = 8;

    // Assign memory blocks to pointers
    mySystem.module_channels   = (mm_addr)(myData+0);
    mySystem.active_channels   = (mm_addr)(myData+(8*MM_SIZEOF_MODCH));
    mySystem.mixing_channels   = (mm_addr)(myData+(8*(MM_SIZEOF_MODCH
                                                      +MM_SIZEOF_ACTCH)));
    mySystem.mixing_memory     = (mm_addr)myMixingBuffer;
    mySystem.wave_memory       = (mm_addr)(myData+(8*(MM_SIZEOF_MODCH
                                                      +MM_SIZEOF_ACTCH
                                                      +MM_SIZEOF_MIXCH)));
    // Pass soundbank address
    mySystem.soundbank         = (mm_addr)soundbank_bin;

    // Initialize Maxmod
    mmInit( &mySystem );
}

u16 __currKeys, __prevKeys;

#define KEY_MASK 0x03FF

inline void PollKeys()
{
    __prevKeys = __currKeys;
    __currKeys = ~REG_KEYINPUT & KEY_MASK;
}

inline u16		currentKeyState()           { return __currKeys; }
inline u16		prevKeyState()              { return __prevKeys; }

inline u16		keyHeld(u16 a_key)       { return (__currKeys & __prevKeys) & a_key; }
inline u16		keyReleased(u16 a_key)   { return (~__currKeys & __prevKeys) & a_key; }
inline u16		keyHit(u16 a_key)        { return (__currKeys & ~__prevKeys) & a_key; }

inline u16		keyStateChange(u16 a_key){ return (__currKeys ^ __prevKeys) & a_key; }

typedef struct
{
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} Bits;
typedef union
{
    Bits bits;
    unsigned char byte;
} CBits;

void delayFrame(u16 frame){
    while(frame > 0){
        mmFrame();
        vsync();
        frame--;
    }
    return;
}

void disp(u16 f){
	for(u32 i=0;i<1200;i++){
			CBits d = (CBits)image_bin[f * 4800 + i];
		
			*((u8*)0x06000000 + (i << 3) + 7) = d.bits.b0;
			*((u8*)0x06000000 + (i << 3) + 6) = d.bits.b1;
			*((u8*)0x06000000 + (i << 3) + 5) = d.bits.b2;
			*((u8*)0x06000000 + (i << 3) + 4) = d.bits.b3;
			*((u8*)0x06000000 + (i << 3) + 3) = d.bits.b4;
			*((u8*)0x06000000 + (i << 3) + 2) = d.bits.b5;
			*((u8*)0x06000000 + (i << 3) + 1) = d.bits.b6;
			*((u8*)0x06000000 + (i << 3) + 0) = d.bits.b7;
		}
}

void dis2(u16 f){
	for(u32 i=2400;i<3600;i++){
			CBits d = (CBits)image_bin[f * 4800 + i];
		
			*((u8*)0x06000000 + (i << 3) + 7) = d.bits.b0;
			*((u8*)0x06000000 + (i << 3) + 6) = d.bits.b1;
			*((u8*)0x06000000 + (i << 3) + 5) = d.bits.b2;
			*((u8*)0x06000000 + (i << 3) + 4) = d.bits.b3;
			*((u8*)0x06000000 + (i << 3) + 3) = d.bits.b4;
			*((u8*)0x06000000 + (i << 3) + 2) = d.bits.b5;
			*((u8*)0x06000000 + (i << 3) + 1) = d.bits.b6;
			*((u8*)0x06000000 + (i << 3) + 0) = d.bits.b7;
		}
}

void dis3(u16 f){
	for(u32 i=1200;i<2400;i++){
			CBits d = (CBits)image_bin[f * 4800 + i];
		
			*((u8*)0x06000000 + (i << 3) + 7) = d.bits.b0;
			*((u8*)0x06000000 + (i << 3) + 6) = d.bits.b1;
			*((u8*)0x06000000 + (i << 3) + 5) = d.bits.b2;
			*((u8*)0x06000000 + (i << 3) + 4) = d.bits.b3;
			*((u8*)0x06000000 + (i << 3) + 3) = d.bits.b4;
			*((u8*)0x06000000 + (i << 3) + 2) = d.bits.b5;
			*((u8*)0x06000000 + (i << 3) + 1) = d.bits.b6;
			*((u8*)0x06000000 + (i << 3) + 0) = d.bits.b7;
		}
}

void dis4(u16 f){
	for(u32 i=3600;i<4800;i++){
			CBits d = (CBits)image_bin[f * 4800 + i];
		
			*((u8*)0x06000000 + (i << 3) + 7) = d.bits.b0;
			*((u8*)0x06000000 + (i << 3) + 6) = d.bits.b1;
			*((u8*)0x06000000 + (i << 3) + 5) = d.bits.b2;
			*((u8*)0x06000000 + (i << 3) + 4) = d.bits.b3;
			*((u8*)0x06000000 + (i << 3) + 3) = d.bits.b4;
			*((u8*)0x06000000 + (i << 3) + 2) = d.bits.b5;
			*((u8*)0x06000000 + (i << 3) + 1) = d.bits.b6;
			*((u8*)0x06000000 + (i << 3) + 0) = d.bits.b7;
		}
}

int main()
{
	//set GBA rendering context to MODE 4 Bitmap Rendering
	*(u16*)0x04000000 = 0x0404;
	
	*((u16*)(0x05000000)) = 0x0000;
	*((u16*)(0x05000002)) = 0x7FFF;
	
	for(u8 i=1;i<255;i++){
		*((u16*)(0x05000000) + i) = 0x7FFF;
	}

    maxmodInit();

    u8 bg = 0;
	u16 f = 0;

	while(bg < 220){
		if(f % 15 == 0){
			mmEffect(bg++);
		}
		
		disp(f);
		mmFrame();
		vsync();
		dis2(f);
		mmFrame();
		vsync();
		dis3(f);
		mmFrame();
		vsync();
		dis4(f++);
		mmFrame();
		vsync();
	}
	while(1){
		vsync();
	}
}