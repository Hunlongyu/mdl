<template>
    <n-space vertical size="large">
        <n-layout has-sider position="absolute">
            <n-layout-sider bordered collapse-mode="width" show-trigger :collapsed-width="64" :width="120">
                <n-menu :collapsed-width="64" :collapsed-icon-size="26" :options="menuOptions"
                    @update:value="menuSelect" />
            </n-layout-sider>
            <n-layout>
                <router-view></router-view>
            </n-layout>
        </n-layout>
    </n-space>
</template>

<script setup>
import { NIcon } from 'naive-ui'
import { DownloadOne, VideoOne, Toolkit, SettingOne, ApiApp } from '@icon-park/vue-next'
import router from '../router'
const menuOptions = [
    {
        label: '下载',
        key: 'download',
        path: 'download',
        icon: renderIcon(DownloadOne)
    },
    {
        label: '录制',
        key: 'record',
        path: 'record',
        icon: renderIcon(VideoOne)
    },
    {
        label: '工具',
        key: 'tools',
        path: 'tools',
        icon: renderIcon(Toolkit)
    },
    {
        label: '设置',
        key: 'settings',
        path: 'settings',
        icon: renderIcon(SettingOne)
    },
    {
        label: '关于',
        key: 'about',
        path: 'about',
        icon: renderIcon(ApiApp)
    }
]

function renderIcon(icon) {
    return () => h(NIcon, null, { default: () => h(icon) })
}

function menuSelect(key, item) {
    router.push(item.path)
}
</script>

<style lang="scss" scoped></style>