/**
 * @author Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @copyright Copyright (C) 2022 Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @par License
 * GNU Lesser General Public License Version 3, 29 June 2007
 * @par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * @par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * @par
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <tesseract_qt/scene_graph/models/limits_standard_item.h>
#include <tesseract_qt/common/standard_item_utils.h>
#include <tesseract_qt/common/standard_item_type.h>
#include <tesseract_qt/common/icon_utils.h>

namespace tesseract_gui
{
LimitsStandardItem::LimitsStandardItem(tesseract_scene_graph::JointLimits::Ptr limits)
  : QStandardItem(icons::getLimitsIcon(), "Limits"), limits(std::move(limits))
{
  ctor();
}

LimitsStandardItem::LimitsStandardItem(const QString& text, tesseract_scene_graph::JointLimits::Ptr limits)
  : QStandardItem(icons::getLimitsIcon(), text), limits(std::move(limits))
{
  ctor();
}

LimitsStandardItem::LimitsStandardItem(const QIcon& icon,
                                       const QString& text,
                                       tesseract_scene_graph::JointLimits::Ptr limits)
  : QStandardItem(icon, text), limits(std::move(limits))
{
  ctor();
}

int LimitsStandardItem::type() const { return static_cast<int>(StandardItemType::SG_LIMITS); }

void LimitsStandardItem::ctor()
{
  appendRow(createStandardItemFloat("lower", limits->lower));
  appendRow(createStandardItemFloat("upper", limits->upper));
  appendRow(createStandardItemFloat("effort", limits->effort));
  appendRow(createStandardItemFloat("velocity", limits->velocity));
  appendRow(createStandardItemFloat("acceleration", limits->acceleration));
}
}  // namespace tesseract_gui