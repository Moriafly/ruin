package com.moriafly.ruin.core

internal interface RuinInterface {

    /**
     * 是否存在不正常的类 [ClassBlacklist]
     */
    fun existBlackClass(): Boolean

    /**
     * 是否存在 Xposed 环境
     */
    fun existXposed(): Boolean

}