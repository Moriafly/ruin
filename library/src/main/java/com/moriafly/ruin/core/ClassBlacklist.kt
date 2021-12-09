/**
 * Copyright (C) 2021 Moriafly
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.moriafly.ruin.core

/**
 * 特征类黑名单
 */
internal object ClassBlacklist {

    /**
     * @app NP Manager
     * @version 3.0.34
     *
     * 去除签名校验 MODEX 3.0 去签特征类
     */
    private const val MODEX_3_0 = "com.minusoneapp.HookApplication"

    /**
     * 黑名单
     */
    val blacklist = listOf(
        MODEX_3_0
    )

}