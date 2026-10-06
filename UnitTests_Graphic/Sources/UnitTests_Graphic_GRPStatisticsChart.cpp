/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPStatisticsChart.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPSTATISTICSCHART
* @brief      Graphic unit tests for GRPSTATISTICSCHART classes
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @cond
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files(the "Software"), to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense, and/ or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of
* the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
* THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* @endcond
*
* --------------------------------------------------------------------------------------------------------------------*/
/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"


/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "UnitTests_Graphic_GRPStatisticsChart.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef GRP_STATISTICSCHARS_ACTIVE
#include "GRPStatisticsChartColumns.h"
#include "GRPStatisticsChartLines.h"
#include "GRPStatisticsChartArea.h"
#include "GRPStatisticsChartBars.h"
#include "GRPStatisticsChartStackedColumns.h"
#include "GRPStatisticsChartPie.h"
#include "GRPStatisticsChartColumns3D.h"
#include "GRPStatisticsChartLines3D.h"
#include "GRPStatisticsChartArea3D.h"
#include "GRPStatisticsChartBars3D.h"
#include "GRPStatisticsChartStackedColumns3D.h"
#include "GRPStatisticsChartPie3D.h"
#include "GRPStatisticsChartBuilderSVG.h"
#include "GRPStatisticsChartData.h"
#include "GRPStatisticsChartConfig.h"
#include "GRPVectorFile.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_STATISTICSCHARS_ACTIVE
namespace TEST_GRPSTATISTICSCHART
{


static bool FillMinimalChartData(GRPSTATISTICSCHART& chart)
{
  if(!chart.GetData())    return false;
  if(!chart.GetConfig())  return false;

  if(!chart.GetData()->AddCategory(_L("Q1"))) return false;
  if(!chart.GetData()->AddCategory(_L("Q2"))) return false;

  GRPSTATISTICSCHARTSERIE* serie = chart.GetData()->AddSerie(_L("Sales"));
  if(!serie) return false;
  if(!serie->AddValue(5.0))  return false;
  if(!serie->AddValue(15.0)) return false;

  chart.GetConfig()->SetTitle(_L("Unit Test Chart"));
  chart.GetConfig()->SetShowLegend(false);
  chart.GetConfig()->SetShowValues(false);

  return true;
}


static void ExpectGenerateSvgOk(GRPSTATISTICSCHART& chart)
{
  GRPSTATISTICSCHARTBUILDERSVG builder;

  ASSERT_TRUE(FillMinimalChartData(chart));
  EXPECT_EQ(chart.Generate(builder, 400.0, 300.0), GRPVECTORFILERESULT_OK);

  XSTRING svg;
  EXPECT_TRUE(builder.GetResult(svg));
  EXPECT_GT(svg.GetSize(), 0);
  EXPECT_NE(svg.Find(_L("<svg"), true), XSTRING_NOTFOUND);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, DataAndConfigBasics)
{
  GRPSTATISTICSCHARTCOLUMNS chart;

  ASSERT_NE(chart.GetData(), (GRPSTATISTICSCHARTDATA*)NULL);
  ASSERT_NE(chart.GetConfig(), (GRPSTATISTICSCHARTCONFIG*)NULL);

  EXPECT_TRUE(chart.GetData()->AddCategory(_L("A")));
  EXPECT_TRUE(chart.GetData()->AddCategory(_L("B")));
  EXPECT_EQ(chart.GetData()->GetNCategories(), 2u);

  GRPSTATISTICSCHARTSERIE* serie = chart.GetData()->AddSerie(_L("S1"));
  ASSERT_NE(serie, (GRPSTATISTICSCHARTSERIE*)NULL);
  EXPECT_TRUE(serie->AddValue(10.0));
  EXPECT_TRUE(serie->AddValue(20.0));
  EXPECT_EQ(serie->GetNValues(), 2u);

  chart.GetConfig()->SetTitle(_L("Unit Test Chart"));
  chart.GetConfig()->SetShowLegend(false);
  EXPECT_EQ(chart.GetConfig()->GetTitle().Compare(_L("Unit Test Chart")), 0);
  EXPECT_FALSE(chart.GetConfig()->GetShowLegend());
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, ColumnsGenerateSvgOffline)
{
  GRPSTATISTICSCHARTCOLUMNS chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, LinesGenerateSvgOffline)
{
  GRPSTATISTICSCHARTLINES chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, AreaGenerateSvgOffline)
{
  GRPSTATISTICSCHARTAREA chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, BarsGenerateSvgOffline)
{
  GRPSTATISTICSCHARTBARS chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, StackedColumnsGenerateSvgOffline)
{
  GRPSTATISTICSCHARTSTACKEDCOLUMNS chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, PieGenerateSvgOffline)
{
  GRPSTATISTICSCHARTPIE chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, Columns3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTCOLUMNS3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, Lines3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTLINES3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, Area3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTAREA3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, Bars3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTBARS3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, StackedColumns3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTSTACKEDCOLUMNS3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, Pie3DGenerateSvgOffline)
{
  GRPSTATISTICSCHARTPIE3D chart;
  ExpectGenerateSvgOk(chart);
}


TEST(UNITTESTS_GRPSTATISTICSCHART_CLASSNAME, GenerateRejectsInvalidSize)
{
  GRPSTATISTICSCHARTCOLUMNS     chart;
  GRPSTATISTICSCHARTBUILDERSVG  builder;

  EXPECT_EQ(chart.Generate(builder, 0.0, 100.0), GRPVECTORFILERESULT_ERRORUNKNOWN);
  EXPECT_EQ(chart.Generate(builder, 100.0, -1.0), GRPVECTORFILERESULT_ERRORUNKNOWN);
}


}
#endif
#endif
#endif
